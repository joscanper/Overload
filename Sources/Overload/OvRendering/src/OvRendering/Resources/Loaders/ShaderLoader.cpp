/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <sstream>
#include <fstream>

#include <OvDebug/Logger.h>

#include <OvRendering/Resources/Loaders/ShaderLoader.h>
#include <OvRendering/Resources/Shader.h>
#include <OvRendering/HAL/ShaderProgram.h>
#include <OvRendering/HAL/ShaderStage.h>

namespace
{
	std::string __FILE_TRACE;
}

std::unique_ptr<OvRendering::HAL::ShaderProgram> CreateProgram(
	const std::string& p_vertexShader,
	const std::string& p_fragmentShader
)
{
	using namespace OvRendering::HAL;
	using namespace OvRendering::Resources;
	using namespace OvRendering::Settings;

	ShaderStage vertexStage{ EShaderType::VERTEX };
	ShaderStage fragmentStage{ EShaderType::FRAGMENT };

	vertexStage.Upload(p_vertexShader);
	fragmentStage.Upload(p_fragmentShader);

	const auto vertexCompilationResult = vertexStage.Compile();
	const auto fragmentCompilationResult = fragmentStage.Compile();

	if (!vertexCompilationResult.success)
	{
		OVLOG_ERROR("[VERTEX COMPILE] \"" + __FILE_TRACE + "\": " + vertexCompilationResult.message);
	}

	if (!fragmentCompilationResult.success)
	{
		OVLOG_ERROR("[FRAGMENT COMPILE] \"" + __FILE_TRACE + "\": " + vertexCompilationResult.message);
	}

	if (vertexCompilationResult.success && fragmentCompilationResult.success)
	{
		auto program = std::make_unique<OvRendering::HAL::ShaderProgram>();
		program->Attach(vertexStage);
		program->Attach(fragmentStage);
		const auto linkResult = program->Link();
		program->Detach(vertexStage);
		program->Detach(fragmentStage);

		if (linkResult.success)
		{
			OVLOG_INFO("[COMPILE] \"" + __FILE_TRACE + "\": Success!");
			return program;
		}
		else
		{
			OVLOG_ERROR("[LINK] \"" + __FILE_TRACE + "\": Failed: " + linkResult.message);
		}
	}

	return nullptr;
}

bool ParseIncludeDirective(const std::string& line, std::string& includeFilePath)
{
	// Find the position of the opening and closing quotes
	size_t start = line.find("\"");
	size_t end = line.find("\"", start + 1);

	// Check if both quotes are found
	if (start != std::string::npos && end != std::string::npos && end > start)
	{
		// Extract the included file path
		includeFilePath = line.substr(start + 1, end - start - 1);
		return true;
	}
	else
	{
		return false;
	}
}

std::string LoadShader(const std::string& p_filePath, OvRendering::Resources::Loaders::ShaderLoader::FilePathParserCallback p_pathParser)
{
	std::ifstream file(p_filePath);

	if (!file.is_open())
	{
		OVLOG_ERROR("Error: Could not open shader file - " + p_filePath);
		return "";
	}

	std::stringstream buffer;
	std::string line;

	while (std::getline(file, line))
	{
		if (line.find("#include") != std::string::npos)
		{
			// If the line contains #include, process the included file
			std::string includeFilePath;
			if (ParseIncludeDirective(line, includeFilePath))
			{
				// Recursively load the included file
				const std::string realIncludeFilePath = p_pathParser ? p_pathParser(includeFilePath) : includeFilePath;
				std::string includedShader = LoadShader(realIncludeFilePath, p_pathParser);
				buffer << includedShader << std::endl;
			}
			else
			{
				OVLOG_ERROR("Error: Invalid #include directive in file - " + p_filePath);
			}
		}
		else {
			// If the line does not contain #include, just append it to the buffer
			buffer << line << std::endl;
		}
	}

	return buffer.str();
}

std::pair<std::string, std::string> ParseShader(const std::string& p_filePath, OvRendering::Resources::Loaders::ShaderLoader::FilePathParserCallback p_pathParser)
{
	const std::string shaderCode = LoadShader(p_filePath, p_pathParser);

	std::istringstream stream(shaderCode);  // Add this line to create a stringstream from shaderCode
	std::string line;
	std::unordered_map<OvRendering::Settings::EShaderType,std::stringstream> ss;

	auto type = OvRendering::Settings::EShaderType::NONE;

	while (std::getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
				type = OvRendering::Settings::EShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = OvRendering::Settings::EShaderType::FRAGMENT;
		}
		else if (type != OvRendering::Settings::EShaderType::NONE)
		{
			ss[type] << line << '\n';
		}
	}

	return
	{
		ss[OvRendering::Settings::EShaderType::VERTEX].str(),
		ss[OvRendering::Settings::EShaderType::FRAGMENT].str()
	};
}

OvRendering::Resources::Shader* OvRendering::Resources::Loaders::ShaderLoader::Create(const std::string& p_filePath, FilePathParserCallback p_pathParser)
{
	__FILE_TRACE = p_filePath;

	auto [vertex, fragment] = ParseShader(p_filePath, p_pathParser);

	if (auto program = CreateProgram(vertex, fragment))
	{
		return new Shader(p_filePath, std::move(program));
	}

	return nullptr;
}

OvRendering::Resources::Shader* OvRendering::Resources::Loaders::ShaderLoader::CreateFromSource(const std::string& p_vertexShader, const std::string& p_fragmentShader)
{
	__FILE_TRACE = "{C++ embedded shader}";

	if (auto program = CreateProgram(p_vertexShader, p_fragmentShader))
	{
		return new Shader("", std::move(program));
	}

	return nullptr;
}

void OvRendering::Resources::Loaders::ShaderLoader::Recompile(Shader& p_shader, const std::string& p_filePath, FilePathParserCallback p_pathParser)
{
	__FILE_TRACE = p_filePath;

	auto [vertex, fragment] = ParseShader(p_filePath, p_pathParser);

	if (auto program = CreateProgram(vertex, fragment))
	{
		p_shader.SetProgram(std::move(program));
	}
	else
	{
		OVLOG_ERROR("[COMPILE] \"" + __FILE_TRACE + "\": Failed! Previous shader version keept");
	}
}

bool OvRendering::Resources::Loaders::ShaderLoader::Destroy(Shader*& p_shader)
{
	if (p_shader)
	{
		delete p_shader;
		p_shader = nullptr;
		return true;
	}
	
	return false;
}

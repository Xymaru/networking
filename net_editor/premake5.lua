project "netEditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    
    files
    {
      "src/**.cpp",
      "src/**.h" 
    }

    includedirs
    {
      "src",
	  "../networking/src",
      "%{IncludeDir.ImGui}",
      "%{IncludeDir.vendor_global}",
      "%{IncludeDir.vendor_networking}",
      "%{IncludeDir.IconFontCppHeaders}"
    }
    links
    {
      "networking",
      "ImGui",
      "%{Library.glew}",
      "%{Library.SDL2}",
      "%{Library.SDL2main}"
    }
    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")
    debugdir("$(SolutionDir)/build")

    filter "system:windows"
      systemversion "latest"
      postbuildcommands
	  {
	    "{COPY} \"%{cfg.buildtarget.relpath}\" \"%{wks.location}build\"",  
      }

    filter "configurations:Debug"
		defines "EM_DEBUG"
		runtime "Debug"
		symbols "On"

    filter "configurations:Release"
		defines "EM_RELEASE"
		runtime "Release"
		optimize "On"
		symbols "On"

    filter "configurations:Dist"
      defines "EM_DIST"
      runtime "Release"
      optimize "On"
      symbols "Off"
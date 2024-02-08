project "networking"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    --pchheader "empch.h"
    --pchsource "src/empch.cpp"

    files
    {
        "src/**.cpp",
        "src/**.h",
        "src/**.inl"
    }
    defines
    {
		"EM_BUILD_DLL"
    }
    includedirs
    {
        "src",
        "%{IncludeDir.vendor_global}",
        "%{IncludeDir.vendor_networking}"
    }
    links
    {
      "%{Library.OpenGL}",
      "%{Library.glew}",
      "%{Library.SDL2}",
      "%{Library.SDL2main}"
    }

    targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

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
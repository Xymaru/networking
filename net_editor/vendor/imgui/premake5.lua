project "ImGui"
kind "StaticLib"
language "C++"
staticruntime "Off"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files {"imconfig.h", "imgui.h", "imgui.cpp", "imgui_draw.cpp", "imgui_internal.h", "imgui_tables.cpp",
       "imgui_widgets.cpp", "imstb_rectpack.h", "imstb_textedit.h", "imstb_truetype.h", "imgui_demo.cpp",
       "imgui_impl_opengl3.h", "imgui_impl_opengl3.cpp", "imgui_impl_sdl2.h", "imgui_impl_sdl2.cpp", "imgui_stdlib.h",
       "imgui_stdlib.cpp"}
includedirs {"$(SolutionDir)libraries/include/sdl2"}

filter "system:windows"
systemversion "latest"
cppdialect "C++17"

filter "system:linux"
pic "On"
systemversion "latest"
cppdialect "C++17"

filter "configurations:Debug"
runtime "Debug"
symbols "On"
optimize "Off"

filter "configurations:Release"
runtime "Release"
optimize "On"
symbols "Off"

filter "configurations:Dist"
runtime "Release"
optimize "On"
symbols "Off"

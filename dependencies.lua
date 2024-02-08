IncludeDir = {}
IncludeDir["vendor_global"]="../libraries/include/"

IncludeDir["SDL2"]="../libraries/include/sld2/"
IncludeDir["glew"]="%../libraries/include/glew/"

IncludeDir["glm"]="../libraries/include/glm/"

IncludeDir["vendor_networking"]="../networking/vendor/"

IncludeDir["IconFontCppHeaders"]="../net_editor/vendor/IconFontCppHeaders/"
IncludeDir["ImGui"]="../net_editor/vendor/imgui/"

LibraryDir={}
LibraryDir["glew"]="../libraries/lib/glew"
LibraryDir["SDL2"]="../libraries/lib/sdl2"

Library={}
Library["OpenGL"]= "opengl32.lib"
Library["glew"] = "%{LibraryDir.glew}/x64/glew32.lib"
Library["SDL2"] = "%{LibraryDir.SDL2}/x64/SDL2.lib"
Library["SDL2main"] = "%{LibraryDir.SDL2}/x64/SDL2main.lib"

group "dependencies"
    include "net_editor/vendor/ImGui"
group ""
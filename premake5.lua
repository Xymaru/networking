workspace "networking"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    startproject "networking"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "dependencies.lua"

include "networking"
include "net_editor"

--
-- If premake command is not supplied an action (target compiler), exit!
--
-- Targets of interest:
--     vs2013     (Visual Studio 2013)
--     vs2015     (Visual Studio 2015)
--     vs2017     (Visual Studio 2017)
--
if (_ACTION == nil) then
return
end

workspace "Challenges"

systemversion("10.0.17763.0")

-- destination directory for generated solution/project files
location ("../" .. _ACTION)

-- destination directory for compiled binary target
targetdir ("../../bin/")
debugdir  ("../../bin/")
-- creating static libraries
kind "ConsoleApp"

-- C++ code in all projects
language "C++"

-- common include directories (all configurations/all projects)
includedirs { 
    "../../include",
}

--
-- Build (solution) configuration options:
--     Release        (Runtime library is Multi-threaded DLL)
--     Debug          (Runtime library is Multi-threaded Debug DLL)
--
configurations { "Release", "Debug" }

architecture "x64"

-- common release configuration flags and symbols
filter { "Release" }
    optimize "On"
    -- favor speed over size
    buildoptions { "/Ot" }
    defines { "WIN32", "NDEBUG"}

-- common debug configuration flags and symbols
filter { "Debug" }
    targetsuffix "_d"
    symbols "On"
    -- enable compiler intrinsics
    defines { "WIN32", "_DEBUG"}

--
-- libraries
--

-- base library
project "Challenges"
    files {
        "../../main.cpp",
        "../../src/**",
        "../../include/**",
    }
    targetname "Challenges"
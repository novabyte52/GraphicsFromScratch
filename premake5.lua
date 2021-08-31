workspace "GraphicsFromScratch"
    architecture "x64"

    configurations
    {
        "Debug"
    }

outputdir = "%{cfg.system}-%{cfg.architecture}"

project "RayTracer"
    location "RayTracer"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    links
    {
        "SDL2"
    }

    filter "configurations:Debug"
        defines "SO_DEBUG"
        symbols "On"
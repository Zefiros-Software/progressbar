project "Progress"
    kind "StaticLib"

    files "progress/src/**.cpp"
        
    cppdialect "C++17"

    zpm.export(function()
        includedirs "progress/include"
        zpm.uses {
            "Zefiros-Software/Preproc",
            "Zefiros-Software/Date",
            "Zefiros-Software/Fmt"
        }
    end)
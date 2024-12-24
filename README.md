# SimpleOv.hpp

# Simpler Overlay For Simple People (:



## Features

- Custom window creation and rendering using Direct3D.
- Single Header File

## Prerequisites

Before using this overlay library, make sure you have the following installed:

- **Direct3D** (DirectX 11 or higher)
- **ImGui** (for rendering UI)
- **C++ Compiler** supporting C++11 or higher
- **Windows Operating System** (since it's Direct3D-based)

## Installation
1. Download the files from github "SimpleOv.hpp" and the ImGui Folder containing the needed files for the overlay.
2. Linking the dx11 library you need to goto "Linker -> Input" and overwrite it with this "d3d11.lib;d3dcompiler.lib;dxgi.lib;%(AdditionalDependencies)"
3. Dx11 Installation(If needed!) -> // DX11 SDK -> https://www.microsoft.com/en-us/download/details.aspx?id=6812 (Install and restart pc)

## Usage

Here's an example of how to use the library:

```cpp
#include "Lib/Overlay/SimpleOv.hpp"

int main()
{
    overlay::SetupWindow();
    if (!(overlay::CreateDeviceD3D(overlay::Window)))
        return 1;

    while (!overlay::ShouldQuit)
    {
        overlay::Render();

        // Access ImGui IO for FPS calculation
        ImGuiIO& io = ImGui::GetIO();
        float fps = 1.0f / io.DeltaTime;

        ImGui::Begin("ImGui");

        // Display FPS in the window
        ImGui::Text("FPS: %.2f", fps);

        ImGui::End();

        overlay::EndRender();
    }

    overlay::CloseOverlay();
}

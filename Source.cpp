#include "SimpleOv.hpp"

int main()
{
    overlay::SetupWindow();
    if (!(overlay::CreateDeviceD3D(overlay::Window)))
        return 1;

    while (!overlay::ShouldQuit)
    {
        overlay::Render();

        ImGuiIO& io = ImGui::GetIO();
        float fps = 1.0f / io.DeltaTime;

        ImGui::Begin("ImGui");

        ImGui::Text("FPS: %.2f", fps);

        ImGui::End();

        ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(50, 150), ImVec2(150, 50), ImColor(255, 255, 255, 255));

        overlay::EndRender();
    }

    overlay::CloseOverlay();
}

#ifndef _SCENE_H_
#define _SCENE_H_

// Ignore warnings generated by using a GUID with std::map.
#pragma warning(disable: 4786)

#include <map>
#include <d3d8.h>
#include <d3dx8.h>
#include "cJSON.h"
#include "Camera.h"
#include "Common.h"
#include "Debug.h"
#include "Gizmo.h"
#include "Grid.h"
#include "Model.h"

struct CameraView
{
  enum Value { Perspective, Top, Left, Front };
};

class CScene
{
public:
  CScene();
  ~CScene();
  bool Create(HWND windowHandle);
  void Delete();
  void Duplicate();
  void Render();
  void Resize();
  void OnMouseWheel(short zDelta);
  void OnNew();
  void OnSave();
  void OnLoad();
  void OnApplyTexture();
  void OnImportModel();
  void OnBuildROM();
  bool Pick(POINT mousePoint);
  void ReleaseResources(ModelRelease::Value type);
  void CheckInput(float);
  void ScreenRaycast(POINT screenPoint, D3DXVECTOR3 *origin, D3DXVECTOR3 *dir);
  void SetCameraView(CameraView::Value view);
  void SetGizmoModifier(GizmoModifierState state);
  CCamera *GetActiveCamera();
  bool ToggleMovementSpace();
  bool ToggleFillMode();

private:
  HWND GetWndHandle();
  void SetTitle(string title);
  void UpdateViewMatrix();
  void ResetCameras();
  
private:
  D3DLIGHT8 m_worldLight;
  D3DMATERIAL8 m_defaultMaterial;
  D3DMATERIAL8 m_selectedMaterial;
  D3DFILLMODE m_fillMode;
  CGizmo m_gizmo;
  CCamera m_cameras[4];
  IDirect3DDevice8 *m_device;
  IDirect3D8 *m_d3d8;
  D3DPRESENT_PARAMETERS m_d3dpp;
  map<GUID, CModel> m_models;
  CGrid m_grid;
  GUID m_selectedModelId;
  float mouseSmoothX, mouseSmoothY;
  CameraView::Value m_activeCameraView;
};

#endif
// Stub for Golem's client-only build of toneengo's XDPH PR #308.
//
// PR #308 (RemoteDesktop portal) is branched off the input-capture fork and
// still ships that fork's InputCapture.cpp, but written against a pre-merge
// revision of the hyprland-input-capture-v1 protocol. Against the merged
// protocol (hyprwm/hyprland-protocols#8) its calls (setFrame/sendCapture/
// sendRelease, the axis enum) no longer exist, so it fails to compile.
//
// Golem runs Deskflow as a *client* and only needs the RemoteDesktop portal
// (input injection) — it never uses the server-side InputCapture portal. So we
// replace InputCapture.cpp with this no-op: CPortalManager only references the
// constructor and zonesChanged() externally, both satisfied here. RemoteDesktop
// and every other portal are left exactly as PR #308 ships them.
//
// Drop this (and the postPatch that installs it, in flake.nix) once #308 is
// rebased so its InputCapture matches the merged protocol.

#include "InputCapture.hpp"

CInputCapturePortal::CInputCapturePortal(SP<CCHyprlandInputCaptureManagerV1> mgr) {
    m_sState.manager = mgr;
}

void CInputCapturePortal::zonesChanged() {}

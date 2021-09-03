/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_NjRAAKMDF,
    0xb0148316,0x259c,0x4525,0xbb,0xd6,0xe0,0x38,0x01,0x56,0x21,0xf6);
// {b0148316-259c-4525-bbd6-e038015621f6}

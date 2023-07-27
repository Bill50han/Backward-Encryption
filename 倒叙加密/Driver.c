#include <ntifs.h>
#include <intrin.h>
#pragma warning(disable: 4702)
#pragma warning(disable: 4100)
volatile NTSTATUS s = STATUS_SUCCESS;

extern void Int0f();
void Unload(_In_ struct _DRIVER_OBJECT* DriverObject);
NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT  DriverObject, _In_ PUNICODE_STRING RegistryPath);

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, Unload)
#pragma alloc_text (PAGE, Int0f)
#endif



void Unload(
    _In_ struct _DRIVER_OBJECT* DriverObject
)
{
    return;
}

NTSTATUS
DriverEntry(
    _In_ PDRIVER_OBJECT  DriverObject,
    _In_ PUNICODE_STRING RegistryPath
    )
{
    DriverObject->DriverUnload = Unload;

    DbgPrint("%p", Int0f);

    return s;
}

/*

eq idtr+f0 0565ee00`00101000
eq idtr+f8 00000000`FFFFF803

FFFF F803 0565 1000
FFFF F803 0565 1000

*/

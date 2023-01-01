#exe{Option(OPTf_WARN_DUP_TYPES, OFF);}
#exe{Option(OPTf_WARN_UNUSED_VAR, OFF);}



/*
public U64 efi_calculate_crc32_t(U8 *Data, U64 DataSize, U32 *Crc32);
*/
/*


/** Functions */

-- not done -->

public U64 efi_get_time_t(CEfiTime *Time, CEfiTimeCapabilities *Capabilities);
public U64 efi_set_time_t(CEfiTime *Time);
public U64 efi_get_wakeup_time_t(Bool *Enable, Bool *Pending, CEfiTime *Time);
public U64 efi_set_wakeup_time_t(Bool Enable, CEfiTime *Time);
public U64 efi_set_virtual_address_map_t(U64 MemoryMapSize, U64 DescriptorSize,  U32 DescriptorVersion, CEfiMemoryDescriptor *VirtualMap);
public U64 efi_convert_pointer_t(U64 DebugDisposition, U8 **Address);
public U64 efi_get_variable_t(U16 *VariableName, CEfiGuid *VendorGuid, U32 *Attributes, U64 *DataSize, U8 *Data);
public U64 efi_get_next_variable_name_t(U64 *VariableNameSize, U16 *VariableName,  CEfiGuid *VendorGuid);
public U64 efi_set_variable_t(U16 *VariableName, CEfiGuid *VendorGuid, U32 Attributes,  U64 DataSize, U8 *Data);
public U64 efi_get_next_high_mono_t(U64 *Count);
public U64 efi_reset_system_t(/* EfiResetType */ U32 ResetType, U64 ResetStatus, U64 DataSize, U16 *ResetData);
public U64 efi_update_capsule_t(CEfiCapsuleHeader **CapsuleHeaderArray, U64 CapsuleCount,  U8 * ScatterGatherList);
public U64 efi_query_capsule_capabilities_t(CEfiCapsuleHeader **CapsuleHeaderArray, U64 CapsuleCount, U64 *MaximumCapsuleSize, /*EfiResetType */ U32 *ResetType);
public U64 efi_query_variable_info_t(U32 Attributes, U64 *MaximumVariableStorageSize, U64 *RemainingVariableStorageSize, U64 *MaximumVariableSize);

public U64 efi_rng_get_info_t(U8 *This, U64 *RNGAlgorithmListSize, CEfiGuid *RNGAlgorithmList);
public U64 efi_rng_get_rng_t(U8 *This, CEfiGuid *RNGAlgorithm, U64 RNGValueLength, U8 *RNGValue);

public U64 efi_serial_reset_t(U8 *This);
public U64 efi_serial_set_attributes_t(U8 *This, U64 BaudRate, U32 ReceiveFifoDepth, U32 Timeout, /*EfiParityType*/ U32 Parity, U8 DataBits, /*efi_stop_bits_type_t*/ U32 StopBits);
public U64 efi_serial_set_control_bits_t(U8 *This, U32 Control);
public U64 efi_serial_get_control_bits_t(U8 *This, U32 *Control);
public U64 efi_serial_write_t(U8 *This, U64 *BufferSize, U8 *Buffer);
public U64 efi_serial_read_t(U8 *This, U64 *BufferSize, U8 *Buffer);

public U64 efi_block_reset_t(U8 *This, Bool ExtendedVerification);
public U64 efi_block_read_t(U8 *This, U32 MediaId, U64 LBA, U64 BufferSize, U8 *Buffer);
public U64 efi_block_write_t(U8 *This, U32 MediaId, U64 LBA, U64 BufferSize, U8 *Buffer);
public U64 efi_block_flush_t(U8 *This);

<-----
*/


/**

The methods are mapped to the EfiCallWrapper using default parameters

*/
/**
File System
*/
public U64 (*efi_volume_open)(CEfiFileHandle **Root, U64 p2=NULL, U64 p3=NULL, CEfiSimpleFileSystemProtocol *this=&SimpleFileSystem, U64 fctn=CEfiSimpleFileSystemProtocol.OpenVolume);

/** Can't be resolve at compile time like others as there coule be many file handles */
public U64 efi_file_open(CEfiFileHandle *File, CEfiFileHandle **NewHandle, U16 *FileName, U64 OpenMode, U64 Attributes) {
  return EfiCallWrapper5(NewHandle, FileName, OpenMode, Attributes, File, File->Open);
}

public U64 efi_file_close(CEfiFileHandle *File) {
  return EfiCallWrapper(0, 0, 0, File, File->Close);
}

public U64 efi_file_delete(CEfiFileHandle *File) {
  return EfiCallWrapper(0, 0, 0, File, File->Delete);
}

public U64 efi_file_read(CEfiFileHandle *File, U64 *BufferSize, U8 *Buffer) {
  return EfiCallWrapper(BufferSize, Buffer, 0, File, File->Read);
}

public U64 efi_file_write(CEfiFileHandle *File, U64 *BufferSize, U8 *Buffer) {
  return EfiCallWrapper(BufferSize, Buffer, 0, File, File->Write);
}

public U64 efi_file_get_pos(CEfiFileHandle *File, U64 *Position) {
  return EfiCallWrapper(Position, 0, 0, File, File->GetPosition);
}

public U64 efi_file_set_pos(CEfiFileHandle *File, U64 Position) {
  return EfiCallWrapper(Position, 0, 0, File, File->SetPosition);
}

public U64 efi_file_get_info(CEfiFileHandle *File, CEfiGuid *InformationType, U64 *BufferSize, U8 *Buffer) {
  return EfiCallWrapper(InformationType, BufferSize, Buffer, File, File->GetInfo);
}

public U64 efi_file_set_info(CEfiFileHandle *File, CEfiGuid *InformationType, U64 BufferSize, U8 *Buffer) {
  return EfiCallWrapper(InformationType, BufferSize, Buffer, File, File->SetInfo);
}

public U64 efi_file_flush(CEfiFileHandle *File) {
  return EfiCallWrapper(0, 0, 0, File, File->Flush);
}


/**
Simple Pointer (Thats mouse to the rest of us)
*/
public U64 (*efi_simple_pointer_reset)(Bool ExtendedVerification, U64 p2 = NULL, U64 p3 = NULL, CEfiSimplePointerProtocol * this = &SimplePointer, U64 fnct=CEfiSimplePointerProtocol.Reset);
public U64 (*efi_simple_pointer_get_state)(CEfiSimplePointerState *State, U64 p2 = NULL, U64 p3 = NULL, CEfiSimplePointerProtocol * this = &SimplePointer, U64 fnct=CEfiSimplePointerProtocol.GetState);

/**
Graphics
*/
public U64 (*efi_gop_query_mode)(U64 ModeNumber, U64 *SizeOfInfo, CEfiGopModeInfo **Info, CEfiGop *This = &GOP, U64 fctn=CEfiGop.QueryMode);
public U64 (*efi_gop_set_mode)(U64 ModeNumber, U64 p3=NULL, U64 p4=NULL , CEfiGop *This = &GOP, U64 fctn=CEfiGop.QueryMode);
/**
Needs wrapper with more params
-- not done --->
public U64 efi_gop_blt(U8 *This, U32 *BltBuffer, /*efi_gop_blt_operation_t*/ U32 BltOperation, U64 SourceX, U64 SourceY, U64 DestinationX, U64 DestionationY, U64 Width, U64 Height, U64 Delta);
<----
*/


/** ConOut

These are "OO" calls where the object is the first parameter passed

CEfiSimpleTextOutputInterface
 */
public U64 (*efi_text_reset)(Bool ExtendedVerification, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset);
public U64 (*efi_text_output_string)(U16 *String, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset );
public U64 (*efi_text_test_string)(U16 *String, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset);
public U64 (*efi_text_query_mode)(U64 ModeNumber, U64 *Column, U64 *Row, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset);
public U64 (*efi_text_set_mode)(U64 ModeNumber, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset);
public U64 (*efi_text_set_attribute)(U64 Attribute, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset);
public U64 (*efi_text_clear_screen)(U64 p1 = NULL, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset);
public U64 (*efi_text_set_cursor)(U64 Column, U64 Row, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset);
public U64 (*efi_text_enable_cursor)(U64 Enable, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = &ConOut, U64 fctn = CEfiSimpleTextOutputInterface.Reset);


/**
Simple Keyboard - returned with Systemtable
*/ 
public U64 (*efi_input_reset)(U64 ExtendedVerification, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleInputInterface *This = &ConIn, U64 fctn = CEfiSimpleInputInterface.Reset);
public U64 (*efi_input_readkey)(CEfiInputType *key, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleInputInterface *This = &ConIn, U64 fctn = CEfiSimpleInputInterface.ReadKeyStroke);


/** BootServices

These are't "OO" cals they are regular function calls

CEfiBootServices
 */

public U64 (*efi_handle_protocol)(U8 * Handle, CEfiGuid *Protocol, U8 **Interface, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.HandleProtocol);
public U64 (*efi_locate_protocol)(CEfiGuid *Protocol, U8 *Registration, U8 **Interface, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.LocateProtocol);
public U64 (*efi_raise_tpl)(U64 NewTpl, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_wait_for_event)(U64 NumberOfEvents, U8 **Event, U64 *Index, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.WaitForEvent);


// *********************** not done --->
public U64 (*efi_restore_tpl)(U64 OldTpl, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RestoreTPL);
public U64 (*efi_allocate_pages)(/* EfiAllocateType*/ U32 Type, /*efi_memory_type_t*/ U32 MemoryType, U64 NoPages, U8 **Memory, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_free_pages)(U8 * Memory, U64 NoPages, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_get_memory_map)(U64 *MemoryMapSize, CEfiMemoryDescriptor *MemoryMap, U64 *MapKey, U64 *DescriptorSize, U32 *DescriptorVersion, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_allocate_pool)(/*efi_memory_type_t*/ U32 PoolType, U64 Size, U8 **Buffer, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_free_pool)(U8 *Buffer, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_create_event)(U32 Type, U64 NotifyTpl, /*efi_event_notify_t*/ U32 NotifyFunction,  U8 *NextContext, U8 * *Event, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_set_timer)(U8 * Event, /*efi_timer_delay_t*/ U32 Type, U64 TriggerTime, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_signal_event)(U8 * Event, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_close_event)(U8 * Event, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_check_event)(U8 * Event, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_register_protocol_notify)(CEfiGuid *Protocol, U8 * Event, U8 **Registration, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_locate_handle)(/*efi_locate_search_type_t*/ U32 SearchType, CEfiGuid *Protocol,  U8 *SearchKey, U64 *BufferSize, U8 * *Buffer, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_locate_device_path)(CEfiGuid *Protocol, CEfiDevicePath **DevicePath,  U8 * *Device, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_install_configuration_table)(CEfiGuid *Guid, U8 *Table, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_image_load)(Bool BootPolicy, U8 * ParentImageHandle, CEfiDevicePath *FilePath, U8 *SourceBuffer, U64 SourceSize, U8 * *ImageHandle, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_image_start)(U8 * ImageHandle, U64 *ExitDataSize, U16 **ExitData, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_exit)(U8 * ImageHandle, U64 ExitStatus, U64 ExitDataSize, U16 *ExitData, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_exit_boot_services)(U8 * ImageHandle, U64 MapKey, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_get_next_monotonic)(U64 *Count, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_stall)(U64 Microseconds, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_set_watchdog_timer)(U64 Timeout, U64 WatchdogCode, U64 DataSize, U16 *WatchdogData, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_connect_controller)(U8 * ControllerHandle, U8 * *DriverImageHandle, CEfiDevicePath *RemainingDevicePath, Bool Recursive, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_disconnect_controller)(U8 * ControllerHandle, U8 * DriverImageHandle, U8 * ChildHandle, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_open_protocol)(U8 * Handle, CEfiGuid *Protocol, U8 **Interface, U8 * AgentHandle, U8 * ControllerHandle, U32 Attributes, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_close_protocol)(U8 * Handle, CEfiGuid *Protocol, U8 * AgentHandle, U8 * ControllerHandle, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_open_protocol_information)(U8 * Handle, CEfiGuid *Protocol,  CEfiOpenProtocolInfoEntry **EntryBuffer, U64 *EntryCount, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_protocols_per_handle)(U8 * Handle, CEfiGuid ***ProtocolBuffer, U64 *ProtocolBufferCount, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_locate_handle_buffer)(/*efi_locate_search_type_t*/ U32 SearchType, CEfiGuid *Protocol, U8 *SearchKey, U64 *NoHandles, U8 * **Handles, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);
public U64 (*efi_calculate_crc32)(U8 *Data, U64 DataSize, U32 *Crc32, U64 p2=NULL, U64 p3=NULL, U64 p4=NULL, U64 bs = &BS, U64 fctn = CEfiBootServices.RaiseTPL);



// ** @TODOneeds new wrapper
/*
public U64 efi_allocate_pages_t(/* EfiAllocateType*/ U32 Type, /*efi_memory_type_t*/ U32 MemoryType, U64 NoPages, U8 **Memory);
public U64 efi_get_memory_map_t(U64 *MemoryMapSize, CEfiMemoryDescriptor *MemoryMap, U64 *MapKey, U64 *DescriptorSize, U32 *DescriptorVersion);
//U0 (*efi_event_notify_t)(U8 * Event, U8 *Context);
public U64 efi_create_event_t(U32 Type, U64 NotifyTpl, /*efi_event_notify_t*/ U32 NotifyFunction,  U8 *NextContext, U8 * *Event);
*/



/**
"Wireup" each of the Efi method pointers to the corrosponding wrapper method

this can't get done in the "main" block it needs to be in a method, as the "main"
block does not get executed, this method is called during startup.
*/
U64 WireEfiMethods() {
  efi_volume_open =

  efi_simple_pointer_reset =
  efi_simple_pointer_get_state =

  efi_gop_query_mode =
  efi_gop_set_mode =

  efi_input_reset =
  efi_input_readkey =  

  efi_text_reset = 
  efi_text_output_string = 
  efi_text_test_string = 
  efi_text_query_mode = 
  efi_text_set_mode = 
  efi_text_set_attribute = 
  efi_text_clear_screen = 
  efi_text_set_cursor = 
  efi_text_enable_cursor = FixPtr(&EfiOOCall4);

  efi_handle_protocol = 
  efi_locate_protocol = 
  efi_raise_tpl = 
  efi_restore_tpl = 
  efi_allocate_pages = 
  efi_free_pages = 
  efi_get_memory_map = 
  efi_allocate_pool = 
  efi_free_pool = 
  efi_create_event = 
  efi_set_timer = 
  efi_wait_for_event = 
  efi_signal_event = 
  efi_close_event = 
  efi_check_event = 
  efi_register_protocol_notify = 
  efi_locate_handle = 
  efi_locate_device_path = 
  efi_install_configuration_table = 
  efi_image_load = 
  efi_image_start = 
  efi_exit = 
  efi_exit_boot_services = 
  efi_get_next_monotonic = 
  efi_stall = 
  efi_set_watchdog_timer = 
  efi_connect_controller = 
  efi_disconnect_controller = 
  efi_open_protocol = 
  efi_close_protocol = 
  efi_open_protocol_information = 
  efi_protocols_per_handle = 
  efi_locate_handle_buffer = 
  efi_calculate_crc32 = FixPtr(&EfiCall4);

  return 0;
}

#exe{Option(OPTf_WARN_DUP_TYPES, ON);}
#exe{Option(OPTf_WARN_UNUSED_VAR, ON);}
 
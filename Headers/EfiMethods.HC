//#include "/Efisource/Headers/Efi.HH"
#exe{Option(OPTf_WARN_DUP_TYPES, OFF);}
#exe{Option(OPTf_WARN_UNUSED_VAR, OFF);}


//#include "/Efisource/Headers/Efi.HH"
/**

Not quite how I wanted to do it, but in the absence of
a better option this will have to do

*/


/*
ConOut


U64 (*efi_text_reset_t)(Bool ExtendedVerification, U64 p2 = NULL, U64 p3 = NULL, CEfiSimpleTextOutputInterface *This = efi.ConOut, U8* fctn = efi.ConOut->Reset);
U64 (*efi_text_output_string_t)(CEfiSimpleTextOutputInterface *This, U16 *String);
U64 (*efi_text_test_string_t)(CEfiSimpleTextOutputInterface *This, U16 *String);
U64 (*efi_text_query_mode_t)(CEfiSimpleTextOutputInterface *This, U64 ModeNumber, U64 *Column, U64 *Row);
U64 (*efi_text_set_mode_t)(CEfiSimpleTextOutputInterface *This, U64 ModeNumber);
U64 (*efi_text_set_attribute_t)(CEfiSimpleTextOutputInterface *This, U64 Attribute);
U64 (*efi_text_clear_screen_t)(CEfiSimpleTextOutputInterface *This);
U64 (*efi_text_set_cursor_t)(CEfiSimpleTextOutputInterface *This, U64 Column, U64 Row);
U64 (*efi_text_enable_cursor_t)(CEfiSimpleTextOutputInterface *This,  Bool Enable);
*/


public U64 EfiConOutReset(Bool ExtendedVerification) {
    return EfiCallWrapper(ExtendedVerification, 0, 0, ConOut, ConOut->Reset);
}

public U64 EfiConOutOutputString(U16 *wString) {
  return EfiCallWrapper(wString, 0, 0, ConOut, ConOut->OutputString);
}

public U64 EfiConOutTestString(U16 *wString) {
  return EfiCallWrapper(wString, 0, 0, ConOut, ConOut->TestString);
}

public U64 EfiConOutQueryMode(U64 ModeNumber, U64 *Column, U64 *Row) {
  return EfiCallWrapper(ModeNumber, Column, Row, ConOut, ConOut->QueryMode);
}

public U64 EfiConOutSetMode(U64 ModeNumber) {
  return EfiCallWrapper(ModeNumber, 0, 0, ConOut, ConOut->SetMode);
}

public U64 EfiConOutSetAttribute(U64 Attribute) {
  return EfiCallWrapper(Attribute, 0, 0, ConOut, ConOut->SetAttribute);
}

public U64 EfiConOutClearScreen() {
  return EfiCallWrapper(0, 0, 0, ConOut, ConOut->ClearScreen);
}

public U64 EfiConOutSetCursor(U64 Column, U64 Row) {
  return EfiCallWrapper(Column, Row, 0, ConOut, ConOut->SetCursorPosition);
}

public U64 EfiConOutEnableCursor(Bool Enable) {
  return EfiCallWrapper(Enable, 0, 0, ConOut, ConOut->EnableCursor);
}


/*
public U64 efi_raise_tpl_t(U64 NewTpl);
public U64 efi_restore_tpl_t(U64 OldTpl);
public U64 efi_allocate_pages_t(/* EfiAllocateType*/ U32 Type, /*efi_memory_type_t*/ U32 MemoryType, U64 NoPages, U8 * *Memory);
public U64 efi_free_pages_t(U8 * Memory, U64 NoPages);
public U64 efi_get_memory_map_t(U64 *MemoryMapSize, CEfiMemoryDescriptor *MemoryMap, U64 *MapKey, U64 *DescriptorSize, U32 *DescriptorVersion);
public U64 efi_allocate_pool_t(/*efi_memory_type_t*/ U32 PoolType, U64 Size, U8 **Buffer);
public U64 efi_free_pool_t(U8 *Buffer);
U0 (*efi_event_notify_t)(U8 * Event, U8 *Context);
public U64 efi_create_event_t(U32 Type, U64 NotifyTpl, /*efi_event_notify_t*/ U32 NotifyFunction,  U8 *NextContext, U8 * *Event);
public U64 efi_set_timer_t(U8 * Event, /*efi_timer_delay_t*/ U32 Type, U64 TriggerTime);
public U64 efi_wait_for_event_t(U64 NumberOfEvents, U8 * *Event, U64 *Index);
public U64 efi_signal_event_t(U8 * Event);
public U64 efi_close_event_t(U8 * Event);
public U64 efi_check_event_t(U8 * Event);
public U64 efi_handle_protocol_t(U8 * Handle, CEfiGuid *Protocol, U8 **Interface);
public U64 efi_register_protocol_notify_t(CEfiGuid *Protocol, U8 * Event, U8 **Registration);
public U64 efi_locate_handle_t(/*efi_locate_search_type_t*/ U32 SearchType, CEfiGuid *Protocol,  U8 *SearchKey, U64 *BufferSize, U8 * *Buffer);
public U64 efi_locate_device_path_t(CEfiGuid *Protocol, CEfiDevicePath **DevicePath,  U8 * *Device);
public U64 efi_install_configuration_table_t(CEfiGuid *Guid, U8 *Table);
public U64 efi_image_load_t(Bool BootPolicy, U8 * ParentImageHandle, CEfiDevicePath *FilePath, U8 *SourceBuffer, U64 SourceSize, U8 * *ImageHandle);
public U64 efi_image_start_t(U8 * ImageHandle, U64 *ExitDataSize, U16 **ExitData);
public U64 efi_exit_t(U8 * ImageHandle, U64 ExitStatus, U64 ExitDataSize, U16 *ExitData);
public U64 efi_exit_boot_services_t(U8 * ImageHandle, U64 MapKey);
public U64 efi_get_next_monotonic_t(U64 *Count);
public U64 efi_stall_t(U64 Microseconds);
public U64 efi_set_watchdog_timer_t(U64 Timeout, U64 WatchdogCode, U64 DataSize, U16 *WatchdogData);
public U64 efi_connect_controller_t(U8 * ControllerHandle, U8 * *DriverImageHandle, CEfiDevicePath *RemainingDevicePath, Bool Recursive);
public U64 efi_disconnect_controller_t(U8 * ControllerHandle, U8 * DriverImageHandle, U8 * ChildHandle);
public U64 efi_open_protocol_t(U8 * Handle, CEfiGuid *Protocol, U8 **Interface, U8 * AgentHandle, U8 * ControllerHandle, U32 Attributes);
public U64 efi_close_protocol_t(U8 * Handle, CEfiGuid *Protocol, U8 * AgentHandle, U8 * ControllerHandle);
public U64 efi_open_protocol_information_t(U8 * Handle, CEfiGuid *Protocol,  CEfiOpenProtocolInfoEntry **EntryBuffer, U64 *EntryCount);
public U64 efi_protocols_per_handle_t(U8 * Handle, CEfiGuid ***ProtocolBuffer, U64 *ProtocolBufferCount);
public U64 efi_locate_handle_buffer_t(/*efi_locate_search_type_t*/ U32 SearchType, CEfiGuid *Protocol, U8 *SearchKey, U64 *NoHandles, U8 * **Handles);
public U64 efi_locate_protocol_t(CEfiGuid *Protocol, U8 *Registration, U8 **Interface);
public U64 efi_calculate_crc32_t(U8 *Data, U64 DataSize, U32 *Crc32);
*/


public U64 efi_raise_tpl_t(U64 NewTpl) {
  return EfiCallWrapper(NewTpl, 0, 0, BS, BS->RaiseTPL);
}

public U64 efi_restore_tpl_t(U64 OldTpl) {
  return EfiCallWrapper(OldTpl, 0, 0, BS, BS->RestoreTPL);
}

// ** @TODOneeds new wrapper
/*
public U64 efi_allocate_pages_t(/* EfiAllocateType*/ U32 Type, /*efi_memory_type_t*/ U32 MemoryType, U64 NoPages, U8 **Memory);
public U64 efi_get_memory_map_t(U64 *MemoryMapSize, CEfiMemoryDescriptor *MemoryMap, U64 *MapKey, U64 *DescriptorSize, U32 *DescriptorVersion);
//U0 (*efi_event_notify_t)(U8 * Event, U8 *Context);
public U64 efi_create_event_t(U32 Type, U64 NotifyTpl, /*efi_event_notify_t*/ U32 NotifyFunction,  U8 *NextContext, U8 * *Event);
*/

public U64 efi_free_pages_t(U8 * Memory, U64 NoPages) {
  return EfiCallWrapper(Memory, NoPages, 0, BS, BS->FreePages);
}

public U64 efi_allocate_pool_t(/*efi_memory_type_t*/ U32 PoolType, U64 Size, U8 **Buffer) {
  return EfiCallWrapper(PoolType, Size, Buffer, BS, BS->AllocatePool);
}

public U64 efi_free_pool_t(U8 *Buffer) {
  return EfiCallWrapper(Buffer, 0, 0, BS, BS->FreePool);
}

public U64 efi_set_timer_t(U8 * Event, /*efi_timer_delay_t*/ U32 Type, U64 TriggerTime) {
  return EfiCallWrapper(Event, Type, TriggerTime, BS, BS->SetTimer);
}

public U64 efi_wait_for_event_t(U64 NumberOfEvents, U8 **Event, U64 *Index) {
  return EfiCallWrapper(NumberOfEvents, Event, Index, BS, BS->WaitForEvent);
}

/*
public U64 efi_signal_event_t(U8 * Event);
public U64 efi_close_event_t(U8 * Event);
public U64 efi_check_event_t(U8 * Event);
public U64 efi_register_protocol_notify_t(CEfiGuid *Protocol, U8 * Event, U8 **Registration);
public U64 efi_locate_handle_t(/*efi_locate_search_type_t*/ U32 SearchType, CEfiGuid *Protocol,  U8 *SearchKey, U64 *BufferSize, U8 **Buffer);
public U64 efi_locate_device_path_t(CEfiGuid *Protocol, CEfiDevicePath **DevicePath,  U8 **Device);
public U64 efi_install_configuration_table_t(CEfiGuid *Guid, U8 *Table);
public U64 efi_image_load_t(Bool BootPolicy, U8 * ParentImageHandle, CEfiDevicePath *FilePath, U8 *SourceBuffer, U64 SourceSize, U8 **ImageHandle);
public U64 efi_image_start_t(U8 * ImageHandle, U64 *ExitDataSize, U16 **ExitData);
public U64 efi_exit_t(U8 * ImageHandle, U64 ExitStatus, U64 ExitDataSize, U16 *ExitData);
public U64 efi_exit_boot_services_t(U8 * ImageHandle, U64 MapKey);
public U64 efi_get_next_monotonic_t(U64 *Count);
public U64 efi_stall_t(U64 Microseconds);
public U64 efi_set_watchdog_timer_t(U64 Timeout, U64 WatchdogCode, U64 DataSize, U16 *WatchdogData);
public U64 efi_connect_controller_t(U8 * ControllerHandle, U8 * *DriverImageHandle, CEfiDevicePath *RemainingDevicePath, Bool Recursive);
public U64 efi_disconnect_controller_t(U8 * ControllerHandle, U8 * DriverImageHandle, U8 * ChildHandle);
public U64 efi_open_protocol_t(U8 * Handle, CEfiGuid *Protocol, U8 **Interface, U8 * AgentHandle, U8 * ControllerHandle, U32 Attributes);
public U64 efi_close_protocol_t(U8 * Handle, CEfiGuid *Protocol, U8 * AgentHandle, U8 * ControllerHandle);
public U64 efi_open_protocol_information_t(U8 * Handle, CEfiGuid *Protocol,  CEfiOpenProtocolInfoEntry **EntryBuffer, U64 *EntryCount);
public U64 efi_protocols_per_handle_t(U8 * Handle, CEfiGuid ***ProtocolBuffer, U64 *ProtocolBufferCount);
public U64 efi_locate_handle_buffer_t(/*efi_locate_search_type_t*/ U32 SearchType, CEfiGuid *Protocol, U8 *SearchKey, U64 *NoHandles, U8 * **Handles);
*/
public U64 efi_handle_protocol_t(U8 * Handle, CEfiGuid *Protocol, U8 **Interface) {
//  return EfiCallWrapper(Handle, Protocol, Interface, BS, BS->HandleProtocol);
  return EfiCallWrapperOrdered(Handle, Protocol, Interface, NULL, BS->HandleProtocol);

}


public U64 efi_locate_protocol_t(CEfiGuid *Protocol, U8 *Registration, U8 **Interface) {
//  return EfiCallWrapper(Protocol, Registration, Interface, BS, BS->LocateProtocol);
//  return EfiCallWrapper(Protocol, Registration, Interface, BS, BS->LocateProtocol);
  return EfiCallWrapperOrdered(Protocol, Registration, Interface, NULL, BS->LocateProtocol);

}

/*
public U64 efi_calculate_crc32_t(U8 *Data, U64 DataSize, U32 *Crc32);
*/
/*


/** Functions */

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

public U64 efi_volume_open_t(U8 *This, CEfiFileHandle **Root);

public U64 efi_file_open_t(CEfiFileHandle *File, CEfiFileHandle **NewHandle, U16 *FileName, U64 OpenMode, U64 Attributes);
public U64 efi_file_close_t(CEfiFileHandle *File);
public U64 efi_file_delete_t(CEfiFileHandle *File);
public U64 efi_file_read_t(CEfiFileHandle *File, U64 *BufferSize, U8 *Buffer);
public U64 efi_file_write_t(CEfiFileHandle *File, U64 *BufferSize, U8 *Buffer);
public U64 efi_file_get_pos_t(CEfiFileHandle *File, U64 *Position);
public U64 efi_file_set_pos_t(CEfiFileHandle *File, U64 Position);
public U64 efi_file_get_info_t(CEfiFileHandle *File, CEfiGuid *InformationType, U64 *BufferSize, U8 *Buffer);
public U64 efi_file_set_info_t(CEfiFileHandle *File, CEfiGuid *InformationType, U64 BufferSize, U8 *Buffer);
public U64 efi_file_flush_t(CEfiFileHandle *File);

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


public U64 efi_gop_query_mode_t(U8 *This, U32 ModeNumber, U64 *SizeOfInfo,  CEfiGopModeInfo **Info);
public U64 efi_gop_set_mode_t(U8 *This, U32 ModeNumber);
public U64 efi_gop_blt_t(U8 *This, U32 *BltBuffer, /*efi_gop_blt_operation_t*/ U32 BltOperation, U64 SourceX, U64 SourceY, U64 DestinationX, U64 DestionationY, U64 Width, U64 Height, U64 Delta);

public U64 efi_simple_pointer_reset_t (U8 *This, Bool ExtendedVerification);
public U64 efi_simple_pointer_get_state_t (U8 *This, CEfiSimplePointerState *State);
*/

#exe{Option(OPTf_WARN_DUP_TYPES, ON);}
#exe{Option(OPTf_WARN_UNUSED_VAR, ON);}

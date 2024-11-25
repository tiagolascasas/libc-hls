# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 20 \
    name size \
    type fifo \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_size \
    op interface \
    ports { size_dout { I 32 vector } size_num_data_valid { I 3 vector } size_fifo_cap { I 3 vector } size_empty_n { I 1 bit } size_read { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 21 \
    name size_c \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_size_c \
    op interface \
    ports { size_c_din { O 32 vector } size_c_num_data_valid { I 3 vector } size_c_fifo_cap { I 3 vector } size_c_full_n { I 1 bit } size_c_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 22 \
    name inStream1 \
    type fifo \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_inStream1 \
    op interface \
    ports { inStream1_dout { I 32 vector } inStream1_num_data_valid { I 3 vector } inStream1_fifo_cap { I 3 vector } inStream1_empty_n { I 1 bit } inStream1_read { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 23 \
    name inStream2 \
    type fifo \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_inStream2 \
    op interface \
    ports { inStream2_dout { I 32 vector } inStream2_num_data_valid { I 3 vector } inStream2_fifo_cap { I 3 vector } inStream2_empty_n { I 1 bit } inStream2_read { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 24 \
    name outStream \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_outStream \
    op interface \
    ports { outStream_din { O 32 vector } outStream_num_data_valid { I 3 vector } outStream_fifo_cap { I 3 vector } outStream_full_n { I 1 bit } outStream_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } ap_continue { I 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}



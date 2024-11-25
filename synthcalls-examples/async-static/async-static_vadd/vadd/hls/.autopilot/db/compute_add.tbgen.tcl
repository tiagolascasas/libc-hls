set moduleName compute_add
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 1
set StallSigGenFlag 1
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {compute_add}
set C_modelType { void 0 }
set ap_memory_interface_dict [dict create]
set C_modelArgList {
	{ size int 32 regular {fifo 0}  }
	{ size_c int 32 regular {fifo 1}  }
	{ inStream1 int 32 regular {fifo 0 volatile } {global 0}  }
	{ inStream2 int 32 regular {fifo 0 volatile } {global 0}  }
	{ outStream int 32 regular {fifo 1 volatile } {global 1}  }
}
set hasAXIMCache 0
set hasAXIML2Cache 0
set AXIMCacheInstDict [dict create]
set C_modelArgMapList {[ 
	{ "Name" : "size", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "size_c", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "inStream1", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "inStream2", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "outStream", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY", "extern" : 0} ]}
# RTL Port declarations: 
set portNum 35
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_continue sc_in sc_logic 1 continue -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ size_dout sc_in sc_lv 32 signal 0 } 
	{ size_num_data_valid sc_in sc_lv 3 signal 0 } 
	{ size_fifo_cap sc_in sc_lv 3 signal 0 } 
	{ size_empty_n sc_in sc_logic 1 signal 0 } 
	{ size_read sc_out sc_logic 1 signal 0 } 
	{ size_c_din sc_out sc_lv 32 signal 1 } 
	{ size_c_num_data_valid sc_in sc_lv 3 signal 1 } 
	{ size_c_fifo_cap sc_in sc_lv 3 signal 1 } 
	{ size_c_full_n sc_in sc_logic 1 signal 1 } 
	{ size_c_write sc_out sc_logic 1 signal 1 } 
	{ inStream1_dout sc_in sc_lv 32 signal 2 } 
	{ inStream1_num_data_valid sc_in sc_lv 3 signal 2 } 
	{ inStream1_fifo_cap sc_in sc_lv 3 signal 2 } 
	{ inStream1_empty_n sc_in sc_logic 1 signal 2 } 
	{ inStream1_read sc_out sc_logic 1 signal 2 } 
	{ inStream2_dout sc_in sc_lv 32 signal 3 } 
	{ inStream2_num_data_valid sc_in sc_lv 3 signal 3 } 
	{ inStream2_fifo_cap sc_in sc_lv 3 signal 3 } 
	{ inStream2_empty_n sc_in sc_logic 1 signal 3 } 
	{ inStream2_read sc_out sc_logic 1 signal 3 } 
	{ outStream_din sc_out sc_lv 32 signal 4 } 
	{ outStream_num_data_valid sc_in sc_lv 3 signal 4 } 
	{ outStream_fifo_cap sc_in sc_lv 3 signal 4 } 
	{ outStream_full_n sc_in sc_logic 1 signal 4 } 
	{ outStream_write sc_out sc_logic 1 signal 4 } 
	{ ap_ext_blocking_n sc_out sc_logic 1 signal -1 } 
	{ ap_str_blocking_n sc_out sc_logic 1 signal -1 } 
	{ ap_int_blocking_n sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_continue", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "continue", "bundle":{"name": "ap_continue", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "size_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "size", "role": "dout" }} , 
 	{ "name": "size_num_data_valid", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "size", "role": "num_data_valid" }} , 
 	{ "name": "size_fifo_cap", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "size", "role": "fifo_cap" }} , 
 	{ "name": "size_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "size", "role": "empty_n" }} , 
 	{ "name": "size_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "size", "role": "read" }} , 
 	{ "name": "size_c_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "size_c", "role": "din" }} , 
 	{ "name": "size_c_num_data_valid", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "size_c", "role": "num_data_valid" }} , 
 	{ "name": "size_c_fifo_cap", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "size_c", "role": "fifo_cap" }} , 
 	{ "name": "size_c_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "size_c", "role": "full_n" }} , 
 	{ "name": "size_c_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "size_c", "role": "write" }} , 
 	{ "name": "inStream1_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inStream1", "role": "dout" }} , 
 	{ "name": "inStream1_num_data_valid", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "inStream1", "role": "num_data_valid" }} , 
 	{ "name": "inStream1_fifo_cap", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "inStream1", "role": "fifo_cap" }} , 
 	{ "name": "inStream1_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inStream1", "role": "empty_n" }} , 
 	{ "name": "inStream1_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inStream1", "role": "read" }} , 
 	{ "name": "inStream2_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "inStream2", "role": "dout" }} , 
 	{ "name": "inStream2_num_data_valid", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "inStream2", "role": "num_data_valid" }} , 
 	{ "name": "inStream2_fifo_cap", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "inStream2", "role": "fifo_cap" }} , 
 	{ "name": "inStream2_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inStream2", "role": "empty_n" }} , 
 	{ "name": "inStream2_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "inStream2", "role": "read" }} , 
 	{ "name": "outStream_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outStream", "role": "din" }} , 
 	{ "name": "outStream_num_data_valid", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "outStream", "role": "num_data_valid" }} , 
 	{ "name": "outStream_fifo_cap", "direction": "in", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "outStream", "role": "fifo_cap" }} , 
 	{ "name": "outStream_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outStream", "role": "full_n" }} , 
 	{ "name": "outStream_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outStream", "role": "write" }} , 
 	{ "name": "ap_ext_blocking_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_ext_blocking_n", "role": "default" }} , 
 	{ "name": "ap_str_blocking_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_str_blocking_n", "role": "default" }} , 
 	{ "name": "ap_int_blocking_n", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ap_int_blocking_n", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "compute_add",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "1", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "4100", "EstimateLatencyMax" : "4100",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "1",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "size", "Type" : "Fifo", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "2",
				"BlockSignal" : [
					{"Name" : "size_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "size_c", "Type" : "Fifo", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "2",
				"BlockSignal" : [
					{"Name" : "size_c_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "inStream1", "Type" : "Fifo", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "0",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_compute_add_Pipeline_execute_fu_52", "Port" : "inStream1", "Inst_start_state" : "2", "Inst_end_state" : "3"}]},
			{"Name" : "inStream2", "Type" : "Fifo", "Direction" : "I", "DependentProc" : ["0"], "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "0",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_compute_add_Pipeline_execute_fu_52", "Port" : "inStream2", "Inst_start_state" : "2", "Inst_end_state" : "3"}]},
			{"Name" : "outStream", "Type" : "Fifo", "Direction" : "O", "DependentProc" : ["0"], "DependentChan" : "0", "DependentChanDepth" : "2", "DependentChanType" : "0",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_compute_add_Pipeline_execute_fu_52", "Port" : "outStream", "Inst_start_state" : "2", "Inst_end_state" : "3"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_compute_add_Pipeline_execute_fu_52", "Parent" : "0", "Child" : ["2"],
		"CDFG" : "compute_add_Pipeline_execute",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "4098", "EstimateLatencyMax" : "4098",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "size_load", "Type" : "None", "Direction" : "I"},
			{"Name" : "inStream1", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "inStream1_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "inStream2", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "inStream2_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "outStream", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "outStream_blk_n", "Type" : "RtlSignal"}]}],
		"Loop" : [
			{"Name" : "execute", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter1", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter1", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "2", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_compute_add_Pipeline_execute_fu_52.flow_control_loop_pipe_sequential_init_U", "Parent" : "1"}]}


set ArgLastReadFirstWriteLatency {
	compute_add {
		size {Type I LastRead 0 FirstWrite -1}
		size_c {Type O LastRead -1 FirstWrite 0}
		inStream1 {Type I LastRead 1 FirstWrite -1}
		inStream2 {Type I LastRead 1 FirstWrite -1}
		outStream {Type O LastRead -1 FirstWrite 1}}
	compute_add_Pipeline_execute {
		size_load {Type I LastRead 0 FirstWrite -1}
		inStream1 {Type I LastRead 1 FirstWrite -1}
		inStream2 {Type I LastRead 1 FirstWrite -1}
		outStream {Type O LastRead -1 FirstWrite 1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "4100", "Max" : "4100"}
	, {"Name" : "Interval", "Min" : "4100", "Max" : "4100"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	size { ap_fifo {  { size_dout fifo_data_in 0 32 }  { size_num_data_valid fifo_status_num_data_valid 0 3 }  { size_fifo_cap fifo_update 0 3 }  { size_empty_n fifo_status 0 1 }  { size_read fifo_port_we 1 1 } } }
	size_c { ap_fifo {  { size_c_din fifo_data_in 1 32 }  { size_c_num_data_valid fifo_status_num_data_valid 0 3 }  { size_c_fifo_cap fifo_update 0 3 }  { size_c_full_n fifo_status 0 1 }  { size_c_write fifo_port_we 1 1 } } }
	inStream1 { ap_fifo {  { inStream1_dout fifo_data_in 0 32 }  { inStream1_num_data_valid fifo_status_num_data_valid 0 3 }  { inStream1_fifo_cap fifo_update 0 3 }  { inStream1_empty_n fifo_status 0 1 }  { inStream1_read fifo_port_we 1 1 } } }
	inStream2 { ap_fifo {  { inStream2_dout fifo_data_in 0 32 }  { inStream2_num_data_valid fifo_status_num_data_valid 0 3 }  { inStream2_fifo_cap fifo_update 0 3 }  { inStream2_empty_n fifo_status 0 1 }  { inStream2_read fifo_port_we 1 1 } } }
	outStream { ap_fifo {  { outStream_din fifo_data_in 1 32 }  { outStream_num_data_valid fifo_status_num_data_valid 0 3 }  { outStream_fifo_cap fifo_update 0 3 }  { outStream_full_n fifo_status 0 1 }  { outStream_write fifo_port_we 1 1 } } }
}

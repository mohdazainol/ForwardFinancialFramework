// (c) Copyright 1995-2014 Xilinx, Inc. All rights reserved.
// 
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
// 
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
// 
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
// 
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
// 
// DO NOT MODIFY THIS FILE.


// IP VLNV: imperial:F3:vivado_activity_thread:1.0
// IP Revision: -1

(* X_CORE_INFO = "vivado_activity_thread_top,Vivado 2013.3" *)
(* CHECK_LICENSE_TYPE = "zynq_system_vivado_activity_thread_0_0,vivado_activity_thread_top,{}" *)
(* DowngradeIPIdentifiedWarnings = "yes" *)
module zynq_system_vivado_activity_thread_0_0 (
  s_axi_CORE_IO_AWADDR,
  s_axi_CORE_IO_AWVALID,
  s_axi_CORE_IO_AWREADY,
  s_axi_CORE_IO_WDATA,
  s_axi_CORE_IO_WSTRB,
  s_axi_CORE_IO_WVALID,
  s_axi_CORE_IO_WREADY,
  s_axi_CORE_IO_BRESP,
  s_axi_CORE_IO_BVALID,
  s_axi_CORE_IO_BREADY,
  s_axi_CORE_IO_ARADDR,
  s_axi_CORE_IO_ARVALID,
  s_axi_CORE_IO_ARREADY,
  s_axi_CORE_IO_RDATA,
  s_axi_CORE_IO_RRESP,
  s_axi_CORE_IO_RVALID,
  s_axi_CORE_IO_RREADY,
  interrupt,
  aclk,
  aresetn
);

(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO AWADDR" *)
input [6 : 0] s_axi_CORE_IO_AWADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO AWVALID" *)
input s_axi_CORE_IO_AWVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO AWREADY" *)
output s_axi_CORE_IO_AWREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO WDATA" *)
input [31 : 0] s_axi_CORE_IO_WDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO WSTRB" *)
input [3 : 0] s_axi_CORE_IO_WSTRB;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO WVALID" *)
input s_axi_CORE_IO_WVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO WREADY" *)
output s_axi_CORE_IO_WREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO BRESP" *)
output [1 : 0] s_axi_CORE_IO_BRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO BVALID" *)
output s_axi_CORE_IO_BVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO BREADY" *)
input s_axi_CORE_IO_BREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO ARADDR" *)
input [6 : 0] s_axi_CORE_IO_ARADDR;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO ARVALID" *)
input s_axi_CORE_IO_ARVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO ARREADY" *)
output s_axi_CORE_IO_ARREADY;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO RDATA" *)
output [31 : 0] s_axi_CORE_IO_RDATA;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO RRESP" *)
output [1 : 0] s_axi_CORE_IO_RRESP;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO RVALID" *)
output s_axi_CORE_IO_RVALID;
(* X_INTERFACE_INFO = "xilinx.com:interface:aximm:1.0 S_AXI_CORE_IO RREADY" *)
input s_axi_CORE_IO_RREADY;
(* X_INTERFACE_INFO = "xilinx.com:signal:interrupt:1.0 interrupt INTERRUPT" *)
output interrupt;
(* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 aclk CLK" *)
input aclk;
(* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 aresetn RST" *)
input aresetn;

  vivado_activity_thread_top #(
    .C_S_AXI_CORE_IO_ADDR_WIDTH(7),
    .C_S_AXI_CORE_IO_DATA_WIDTH(32)
  ) inst (
    .s_axi_CORE_IO_AWADDR(s_axi_CORE_IO_AWADDR),
    .s_axi_CORE_IO_AWVALID(s_axi_CORE_IO_AWVALID),
    .s_axi_CORE_IO_AWREADY(s_axi_CORE_IO_AWREADY),
    .s_axi_CORE_IO_WDATA(s_axi_CORE_IO_WDATA),
    .s_axi_CORE_IO_WSTRB(s_axi_CORE_IO_WSTRB),
    .s_axi_CORE_IO_WVALID(s_axi_CORE_IO_WVALID),
    .s_axi_CORE_IO_WREADY(s_axi_CORE_IO_WREADY),
    .s_axi_CORE_IO_BRESP(s_axi_CORE_IO_BRESP),
    .s_axi_CORE_IO_BVALID(s_axi_CORE_IO_BVALID),
    .s_axi_CORE_IO_BREADY(s_axi_CORE_IO_BREADY),
    .s_axi_CORE_IO_ARADDR(s_axi_CORE_IO_ARADDR),
    .s_axi_CORE_IO_ARVALID(s_axi_CORE_IO_ARVALID),
    .s_axi_CORE_IO_ARREADY(s_axi_CORE_IO_ARREADY),
    .s_axi_CORE_IO_RDATA(s_axi_CORE_IO_RDATA),
    .s_axi_CORE_IO_RRESP(s_axi_CORE_IO_RRESP),
    .s_axi_CORE_IO_RVALID(s_axi_CORE_IO_RVALID),
    .s_axi_CORE_IO_RREADY(s_axi_CORE_IO_RREADY),
    .interrupt(interrupt),
    .aclk(aclk),
    .aresetn(aresetn)
  );
endmodule

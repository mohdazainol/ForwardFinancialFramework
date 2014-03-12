-- (c) Copyright 1995-2014 Xilinx, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
-- DO NOT MODIFY THIS FILE.

-- IP VLNV: imperial:F3:vivado_activity_thread:1.0
-- IP Revision: -1

-- The following code must appear in the VHDL architecture header.

------------- Begin Cut here for COMPONENT Declaration ------ COMP_TAG
COMPONENT zynq_system_vivado_activity_thread_0_0
  PORT (
    s_axi_CORE_IO_AWADDR : IN STD_LOGIC_VECTOR(6 DOWNTO 0);
    s_axi_CORE_IO_AWVALID : IN STD_LOGIC;
    s_axi_CORE_IO_AWREADY : OUT STD_LOGIC;
    s_axi_CORE_IO_WDATA : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    s_axi_CORE_IO_WSTRB : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s_axi_CORE_IO_WVALID : IN STD_LOGIC;
    s_axi_CORE_IO_WREADY : OUT STD_LOGIC;
    s_axi_CORE_IO_BRESP : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    s_axi_CORE_IO_BVALID : OUT STD_LOGIC;
    s_axi_CORE_IO_BREADY : IN STD_LOGIC;
    s_axi_CORE_IO_ARADDR : IN STD_LOGIC_VECTOR(6 DOWNTO 0);
    s_axi_CORE_IO_ARVALID : IN STD_LOGIC;
    s_axi_CORE_IO_ARREADY : OUT STD_LOGIC;
    s_axi_CORE_IO_RDATA : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    s_axi_CORE_IO_RRESP : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    s_axi_CORE_IO_RVALID : OUT STD_LOGIC;
    s_axi_CORE_IO_RREADY : IN STD_LOGIC;
    interrupt : OUT STD_LOGIC;
    aclk : IN STD_LOGIC;
    aresetn : IN STD_LOGIC
  );
END COMPONENT;
ATTRIBUTE SYN_BLACK_BOX : BOOLEAN;
ATTRIBUTE SYN_BLACK_BOX OF zynq_system_vivado_activity_thread_0_0 : COMPONENT IS TRUE;
ATTRIBUTE BLACK_BOX_PAD_PIN : STRING;
ATTRIBUTE BLACK_BOX_PAD_PIN OF zynq_system_vivado_activity_thread_0_0 : COMPONENT IS "s_axi_CORE_IO_AWADDR[6:0],s_axi_CORE_IO_AWVALID,s_axi_CORE_IO_AWREADY,s_axi_CORE_IO_WDATA[31:0],s_axi_CORE_IO_WSTRB[3:0],s_axi_CORE_IO_WVALID,s_axi_CORE_IO_WREADY,s_axi_CORE_IO_BRESP[1:0],s_axi_CORE_IO_BVALID,s_axi_CORE_IO_BREADY,s_axi_CORE_IO_ARADDR[6:0],s_axi_CORE_IO_ARVALID,s_axi_CORE_IO_ARREADY,s_axi_CORE_IO_RDATA[31:0],s_axi_CORE_IO_RRESP[1:0],s_axi_CORE_IO_RVALID,s_axi_CORE_IO_RREADY,interrupt,aclk,aresetn";

-- COMP_TAG_END ------ End COMPONENT Declaration ------------

-- The following code must appear in the VHDL architecture
-- body. Substitute your own instance name and net names.

------------- Begin Cut here for INSTANTIATION Template ----- INST_TAG
your_instance_name : zynq_system_vivado_activity_thread_0_0
  PORT MAP (
    s_axi_CORE_IO_AWADDR => s_axi_CORE_IO_AWADDR,
    s_axi_CORE_IO_AWVALID => s_axi_CORE_IO_AWVALID,
    s_axi_CORE_IO_AWREADY => s_axi_CORE_IO_AWREADY,
    s_axi_CORE_IO_WDATA => s_axi_CORE_IO_WDATA,
    s_axi_CORE_IO_WSTRB => s_axi_CORE_IO_WSTRB,
    s_axi_CORE_IO_WVALID => s_axi_CORE_IO_WVALID,
    s_axi_CORE_IO_WREADY => s_axi_CORE_IO_WREADY,
    s_axi_CORE_IO_BRESP => s_axi_CORE_IO_BRESP,
    s_axi_CORE_IO_BVALID => s_axi_CORE_IO_BVALID,
    s_axi_CORE_IO_BREADY => s_axi_CORE_IO_BREADY,
    s_axi_CORE_IO_ARADDR => s_axi_CORE_IO_ARADDR,
    s_axi_CORE_IO_ARVALID => s_axi_CORE_IO_ARVALID,
    s_axi_CORE_IO_ARREADY => s_axi_CORE_IO_ARREADY,
    s_axi_CORE_IO_RDATA => s_axi_CORE_IO_RDATA,
    s_axi_CORE_IO_RRESP => s_axi_CORE_IO_RRESP,
    s_axi_CORE_IO_RVALID => s_axi_CORE_IO_RVALID,
    s_axi_CORE_IO_RREADY => s_axi_CORE_IO_RREADY,
    interrupt => interrupt,
    aclk => aclk,
    aresetn => aresetn
  );
-- INST_TAG_END ------ End INSTANTIATION Template ---------


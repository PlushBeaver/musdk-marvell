/************************************************************************
*  Copyright (C) 2018 Marvell International Ltd.
*
*  This program is free software: you can redistribute it and/or
*  modify it under the terms of the GNU General Public License as
*  published by the Free Software Foundation, either version 2 of the
*  License, or any later version.
*
*  This program is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  General Public License for more details.
*
*******************************************************************************/

#ifndef _MV_DP_FW_IF_H_
#define _MV_DP_FW_IF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "mv_nss_dp.h"


struct mv_dp_msg_header{
	uint16_t 	inst_num;/* Number of instances for multiple get/set requests */
	uint8_t		flags; /* type of message:no ACK required/ACK or Reply is required */
	uint8_t		rc; /* Request return code */
};

/* DPAPI Message OPCODES
*
*
*/
#define MV_DP_EVENT_FIRST_ID			(0x0090)

enum mv_dp_msg_id {
	MV_DP_MSGID_CTX				= (0x0000),
	MV_DP_MSGID_INIT			= (0x0001),
	MV_DP_MSGID_SHUTDOWN			= (0x0002),
	MV_DP_MSGID_VER				= (0x0003),
	MV_DP_MSGID_CLIENT_SET			= (0x0004),
	MV_DP_MSGID_CLIENT_GET			= (0x0005),
	MV_DP_MSGID_CLIENT_GET_MAC		= (0x0006),
	MV_DP_MSGID_CLIENT_DEL			= (0x0007),
	MV_DP_MSGID_PORT_SET			= (0x0008),
	MV_DP_MSGID_PORT_DEL			= (0x0009),
	MV_DP_MSGID_PORT_GET			= (0x000A),
	MV_DP_MSGID_PORT_STATS_GET_BULK		= (0x000B),
	MV_DP_MSGID_PORT_STATS_GET		= (0x000C),
	MV_DP_MSGID_PORT_STATS_RST		= (0x000D),
	MV_DP_MSGID_VLAN_CFG_GET		= (0x000E),
	MV_DP_MSGID_VLAN_CFG_GET_BY_ID		= (0x000F),
	MV_DP_MSGID_VLAN_CFG_SET		= (0x0010),
	MV_DP_MSGID_VLAN_CFG_DEL		= (0x0011),
	MV_DP_MSGID_EXCEPT_CFG_GET		= (0x0012),
	MV_DP_MSGID_EXCEPT_CFG_SET		= (0x0013),
	MV_DP_MSGID_EXCEPT_STAT_GET		= (0x0014),
	MV_DP_MSGID_EXCEPT_STAT_RST		= (0x0015),
	MV_DP_MSGID_EXCEPT_STAT_GET_BULK	= (0x0016),
	MV_DP_MSGID_DTLS_SET			= (0x0017),
	MV_DP_MSGID_DTLS_DELETE			= (0x0018),
	MV_DP_MSGID_DTLS_GET			= (0x0019),
	MV_DP_MSGID_DP_PORT_DST_SET		= (0x001A),
	MV_DP_MSGID_FLOW_SET			= (0x001B),
	MV_DP_MSGID_FLOW_GET			= (0x001C),
	MV_DP_MSGID_FLOW_DELETE			= (0x001D),
	MV_DP_MSGID_FLOW_DELETE_ALL		= (0x001E),
	MV_DP_MSGID_FLOW_STATUS_SET		= (0x001F),
	MV_DP_MSGID_FLOW_STATUS_GET		= (0x0020),
	MV_DP_MSGID_FLOW_STATS_GET		= (0x0021),
	MV_DP_MSGID_FLOW_STATS_RESET		= (0x0022),
	MV_DP_MSGID_FLOW_STATS_GET_BULK		= (0x0023),
	MV_DP_MSGID_FLOW_COUNT_GET		= (0x0024),
	MV_DP_MSGID_INGRESS_QUEUE_CFG_SET	= (0x0025),
	MV_DP_MSGID_INGRESS_QUEUE_CFG_GET	= (0x0026),
	MV_DP_MSGID_INGRESS_PRIO_CFG_SET	= (0x0027),
	MV_DP_MSGID_INGRESS_PRIO_CFG_GET	= (0x0028),
	MV_DP_MSGID_INGRESS_QOS_POLICY_SET	= (0x0029),
	MV_DP_MSGID_INGRESS_QOS_POLICY_GET	= (0x002A),
	MV_DP_MSGID_EGRESS_QOS_POLICY_SET	= (0x002B),
	MV_DP_MSGID_EGRESS_QOS_POLICY_GET	= (0x002C),
	MV_DP_MSGID_HASH_PROFILE_SET		= (0x002D),
	MV_DP_MSGID_HASH_PROFILE_DELETE		= (0x002E),
	MV_DP_MSGID_EGRESS_QUEUE_CFG_SET	= (0x002F),
	MV_DP_MSGID_EGRESS_QUEUE_CFG_GET	= (0x0030),
	MV_DP_MSGID_EGRESS_PRIO_CFG_SET		= (0x0031),
	MV_DP_MSGID_EGRESS_PRIO_CFG_GET		= (0x0032),
	MV_DP_MSGID_SYS_DIMENSION_GET		= (0x0033),
	MV_DP_MSGID_HASH_PROFILE_GET		= (0x0034),
	MV_DP_MSGID_MIRROR_TUNNEL_SET		= (0x0035),
	MV_DP_MSGID_MIRROR_TUNNEL_GET		= (0x0036),
	MV_DP_MSGID_MIRROR_CFG_SET		= (0x0037),
	MV_DP_MSGID_MIRROR_CFG_GET		= (0x0038),
	MV_DP_MSGID_MC_BRIDGED_CFG_SET		= (0x0039),
	MV_DP_MSGID_MC_BRIDGED_CFG_DELETE	= (0x003A),
	MV_DP_MSGID_MC_BRIDGED_CFG_GET		= (0x003B),
	MV_DP_MSGID_MC_TUNNELED_CFG_SET		= (0x003C),
	MV_DP_MSGID_MC_TUNNELED_CFG_DELETE	= (0x003D),
	MV_DP_MSGID_MC_TUNNELED_CFG_GET		= (0x003E),
	MV_DP_MSGID_DBG_NSS_MEM_WRITE		= (0x003F),
	MV_DP_MSGID_DBG_NSS_MEM_READ		= (0x0040),
	MV_DP_MSGID_DBG_DROP_REASON_STATS_GET = (0x0041),
	MV_DP_MSGID_DBG_DROP_REASON_STATS_RST = (0x0042),
	MV_DP_MSGID_DBG_DROP_REASON_STATS_RST_ALL = (0x0043),
	MV_DP_MSGID_INGRESS_Q_STATS_GET     = (0x0044),
	MV_DP_MSGID_INGRESS_Q_STATS_RESET   = (0x0045),
	MV_DP_MSGID_EGRESS_Q_STATS_GET      = (0x0046),
	MV_DP_MSGID_EGRESS_Q_STATS_RESET    = (0x0047),
	MV_DP_MSGID_BYPASS_STATE_SET        = (0x0048),
	MV_DP_MSGID_BYPASS_STATE_GET        = (0x0049),
	MV_DP_MSGID_VXLAN_VNI_CFG_SET		= (0x004A),
	MV_DP_MSGID_VXLAN_VNI_CFG_GET		= (0x004B),
	MV_DP_MSGID_VXLAN_VNI_CFG_DEL		= (0x004C),
	MV_DP_NUM_EXTERNAL_MESSAGES,

	MV_DP_MSGID_EPORT_SET			= (0x0080), /*not trasmitted - used by DPAPI implementation*/
	MV_DP_MSGID_CWPORT_SET			= (0x0081),
	MV_DP_MSGID_LAGPORT_SET			= (0x0082),
	MV_DP_MSGID_CPUPORT_SET			= (0x0083),
	MV_DP_MSGID_VXPORT_SET			= (0x0084),
	MV_DP_MSGID_EPORT_GET			= (0x0085),
	MV_DP_MSGID_CWPORT_GET			= (0x0086),
	MV_DP_MSGID_LAGPORT_GET			= (0x0087),
	MV_DP_MSGID_CPUPORT_GET			= (0x0088),
	MV_DP_MSGID_VXPORT_GET			= (0x0089),
	MV_DP_MSGID_PORT_LINK_GET		= (0x008a),
	MV_DP_MSGID_NOP				= (0x008b),

	MV_DP_MSGID_EVT_SYS = (MV_DP_EVENT_FIRST_ID | 0x0000),
	MV_DP_MSGID_EVT_SYS_MSG = (MV_DP_EVENT_FIRST_ID | 0x0001),
	MV_DP_MSGID_LAST = ((MV_DP_MSGID_EVT_SYS_MSG) + 1)
};
#define MV_DP_MSGID_FIRST		(MV_DP_MSGID_CTX)

#define MV_DP_MSGID_EVENT_LAST		(MV_DP_MSGID_EVT_SYS_MSG + 1)
#define MV_DP_MSGID_IS_OK(o)		(((o) >= MV_DP_MSGID_FIRST) && ((o) < MV_DP_MSGID_LAST))

#define MV_DP_EVENTID_IS_OK(o)		(((o) >= MV_DP_MSGID_EVT_SYS) && ((o) < MV_DP_MSGID_LAST))

#define MV_DP_SYSTEM_MSG_SIZE		(MV_DP_CFH_MSG_BUF_SIZE_B) /*msg exception must fit into CFH */

#define MV_DP_EVENTID_LAST		(MV_DP_MSGID_EVENT_LAST & ~MV_DP_EVENT_FIRST_ID)
#define MV_DP_MSGID_TO_EVENTID(o)	((o) & ~MV_DP_EVENT_FIRST_ID)
#define MV_DP_EVENTID_TO_MSGID(o)	((o) | MV_DP_EVENT_FIRST_ID)


					/*size in 4B words: 32 -- total CFH - msg_header*/
#define MV_DP_CFH_MSG_BUF_SIZE_W	(64)
#define MV_DP_CFH_MSG_BUF_SIZE_B	(MV_DP_CFH_MSG_BUF_SIZE_W * 4)

/*#define MV_DP_PORT_ID_IS_OK(p)		((p) >= MV_NSS_DP_PORT_RESERVED && (p) <= MV_NSS_DP_PORT_ALL)*/
#define MV_DP_EPORT_ID_IS_OK(p)		((p) >= MV_NSS_DP_ETH_PORT_MIN && (p) <= MV_NSS_DP_ETH_PORT_MAX)
/*#define MV_DP_CPUPORT_ID_IS_OK(p)	(((p) >= MV_NSS_DP_CPU_PORT_MIN && (p) <= MV_NSS_DP_CPU_PORT_MAX) \*/
/*										|| MV_DP_PORT_ID_IS_OK(p))*/



/****************Message definitions*******************/

/*WORDX ---- X is Word number to make it more readable*/

/*extended error information on status fail response  could be used for extended ERROR -- 0 for now i.e. none*/
#define MV_DP_MSG_FAIL_RX_STATUS_SIZE	(0)
#define MV_DP_MSG_FAIL_RX_STATUS_WORD0	(0)
#define MV_DP_MSG_FAIL_RX_STATUS_OFFS	(0)
#define MV_DP_MSG_FAIL_RX_STATUS_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_FAIL_RX_STATUS_GET(v)	(((v) >> MV_DP_MSG_FAIL_RX_STATUS_OFFS) & MV_DP_MSG_FAIL_RX_STATUS_MASK)

/*msg NOP*/
#define MV_DP_MSG_NOP_COOKIE_VAL	(0xDEADBEEF)
#define MV_DP_MSG_NOP_COOKIE_WORD0	(0)
#define MV_DP_MSG_NOP_COOKIE_OFFS	(0)
#define MV_DP_MSG_NOP_COOKIE_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_NOP_COOKIE_SET(v)	((((v) & MV_DP_MSG_NOP_COOKIE_MASK) << MV_DP_MSG_NOP_COOKIE_OFFS))
#define MV_DP_MSG_NOP_COOKIE_GET(v)	(((v) >> MV_DP_MSG_NOP_COOKIE_OFFS) & MV_DP_MSG_NOP_COOKIE_MASK)
#define MV_DP_MSG_NOP_TX_SIZE		(4)
#define MV_DP_MSG_NOP_RX_SIZE		(4)


#define MV_DP_MSG_CTX_OPC_WORD0		(0)
#define MV_DP_MSG_CTX_OPC_OFFS		(0)
#define MV_DP_MSG_CTX_OPC_MASK		(0x0000FFFF)
#define MV_DP_MSG_CTX_OPC_SET(v)	((((v) & MV_DP_MSG_CTX_OPC_MASK) << MV_DP_MSG_CTX_OPC_OFFS))
#define MV_DP_MSG_CTX_OPC_GET(v)	(((v) >> MV_DP_MSG_CTX_OPC_OFFS) & MV_DP_MSG_CTX_OPC_MASK)

#define MV_DP_MSG_CTX_CNT_WORD0		(0)
#define MV_DP_MSG_CTX_CNT_OFFS		(16)
#define MV_DP_MSG_CTX_CNT_MASK		(0x0000FFFF)
#define MV_DP_MSG_CTX_CNT_SET(v)	((((v) & MV_DP_MSG_CTX_CNT_MASK) << MV_DP_MSG_CTX_CNT_OFFS))
#define MV_DP_MSG_CTX_CNT_GET(v)	(((v) >> MV_DP_MSG_CTX_CNT_OFFS) & MV_DP_MSG_CTX_CNT_MASK)

#define MV_DP_MSG_CTX_TX_SIZE		(4)
#define MV_DP_MSG_CTX_RX_SIZE		(MV_DP_MSG_SIZE_INVALID)


/***************msg VER**************************************************************************/
#define MV_DP_MSG_VER_MAJ_WORD0		(0)
#define MV_DP_MSG_VER_MAJ_OFFS		(16)
#define MV_DP_MSG_VER_MAJ_MASK		(0x000000FF)
#define MV_DP_MSG_VER_MAJ_GET(v)	(((v) >> MV_DP_MSG_VER_MAJ_OFFS) & MV_DP_MSG_VER_MAJ_MASK)

#define MV_DP_MSG_VER_MID_WORD0		(0)
#define MV_DP_MSG_VER_MID_OFFS		(8)
#define MV_DP_MSG_VER_MID_MASK		(0x000000FF)
#define MV_DP_MSG_VER_MID_GET(v)	(((v) >> MV_DP_MSG_VER_MID_OFFS) & MV_DP_MSG_VER_MID_MASK)

#define MV_DP_MSG_VER_MIN_WORD0		(0)
#define MV_DP_MSG_VER_MIN_OFFS		(0)
#define MV_DP_MSG_VER_MIN_MASK		(0x000000FF)
#define MV_DP_MSG_VER_MIN_GET(v)	(((v) >> MV_DP_MSG_VER_MIN_OFFS) & MV_DP_MSG_VER_MIN_MASK)

#define MV_DP_MSG_VER_TX_SIZE		(0)
#define MV_DP_MSG_VER_RX_SIZE		(4)

/***********************INIT*************************************************************************/
/*INIT message:
	TX: - Default dest vport
	RX: - FW Version as in get version
*
*****************************************************************************************************/

#define MV_DP_MSG_INIT_RX_SIZE			(4)
#define MV_DP_MSG_INIT_TX_SIZE			(4)

#define MV_DP_MSG_INIT_DST_PORT_ID_WORD0	(0)
#define MV_DP_MSG_INIT_DST_PORT_ID_OFFS		(0)
#define MV_DP_MSG_INIT_DST_PORT_ID_MASK		(0xFF)
#define MV_DP_MSG_INIT_DST_PORT_ID_SET(v)	(((v) & MV_DP_MSG_INIT_DST_PORT_ID_MASK) \
									<< MV_DP_MSG_INIT_DST_PORT_ID_OFFS)
#define MV_DP_MSG_INIT_DST_PORT_ID_GET(v)	(((v) >> MV_DP_MSG_INIT_DST_PORT_ID_OFFS) \
									& MV_DP_MSG_INIT_DST_PORT_ID_MASK)

#define MV_DP_MSG_INIT_RFU_WORD0		(0)
#define MV_DP_MSG_INIT_RFU_OFFS			(8)
#define MV_DP_MSG_INIT_RFU_MASK			(0xFFFFFF)

/*INIT RX: -- FW Version*/
#define MV_DP_MSG_INIT_VER_MAJ_WORD0		(0)
#define MV_DP_MSG_INIT_VER_MAJ_OFFS		(16)
#define MV_DP_MSG_INIT_VER_MAJ_MASK		(0x000000FF)
#define MV_DP_MSG_INIT_VER_MAJ_GET(v)		(((v) >> MV_DP_MSG_VER_MAJ_OFFS) & MV_DP_MSG_VER_MAJ_MASK)

#define MV_DP_MSG_INIT_VER_MID_WORD0		(0)
#define MV_DP_MSG_INIT_VER_MID_OFFS		(8)
#define MV_DP_MSG_INIT_VER_MID_MASK		(0x000000FF)
#define MV_DP_MSG_INIT_VER_MID_GET(v)		(((v) >> MV_DP_MSG_VER_MID_OFFS) & MV_DP_MSG_VER_MID_MASK)

#define MV_DP_MSG_INIT_VER_MIN_WORD0		(0)
#define MV_DP_MSG_INIT_VER_MIN_OFFS		(0)
#define MV_DP_MSG_INIT_VER_MIN_MASK		(0x000000FF)
#define MV_DP_MSG_INIT_VER_MIN_GET(v)		(((v) >> MV_DP_MSG_VER_MIN_OFFS) & MV_DP_MSG_VER_MIN_MASK)



/*msg shutdown- no input-output*/
#define MV_DP_MSG_SHUTDOWN_RX_SIZE		(0)
#define MV_DP_MSG_SHUTDOWN_TX_SIZE		(0)

/***********************CLIENT MSGs**************************************/
/*
*Client_set request -- ALL client fields except for IND,
			n's record is at byte CLIENT_SET_TX_SIZE * n [0 based]
*Client_set reply   -- NONE
*
*Client_get_byMAC request   -- MAC field only. n's MAC is at MAC_SIZE*n,
*Client_get_byIndex request -- Client_INDex field only. single request only
*Client_get reply           -- All fields except for Client_INDex
*
*Client delete request -- only MAC, in case of bulk, n's MAC is at MAC_SIZE*n,
*Client delete reply   -- NONE
*MAC address is not swapped as it is already in Network order.
*
*Client delete all request -- NONE
*Client delete all reply   -- NONE

*************************************************************************/

#define MV_DP_MSG_CLIENT_SET_TX_SIZE		(16)
#define MV_DP_MSG_CLIENT_SET_RX_SIZE		(0)

#define MV_DP_MSG_CLIENT_GET_IND_TX_SIZE	(4)
#define MV_DP_MSG_CLIENT_GET_IND_RX_SIZE	(16)

#define MV_DP_MSG_CLIENT_GET_MAC_TX_SIZE	(6)
#define MV_DP_MSG_CLIENT_GET_MAC_RX_SIZE	(16)

#define MV_DP_MSG_CLIENT_DEL_TX_SIZE		(6)
#define MV_DP_MSG_CLIENT_DEL_RX_SIZE		(0)

#define MV_DP_MSG_CLIENT_DEL_ALL_TX_SIZE	(0)
#define MV_DP_MSG_CLIENT_DEL_ALL_RX_SIZE	(0)

/**********Client fields offsets**************************/
#define MV_DP_MSG_CLIENT_MAC_WORD0		(0)
#define MV_DP_MSG_CLIENT_MAC_OFFS		(0)
#define MV_DP_MSG_CLIENT_MAC_SIZE		(6)	/*size in bytes */

#define MV_DP_MSG_CLIENT_RFU1_WORD1		(1)	/*RFU no set/get */
#define MV_DP_MSG_CLIENT_RFU1_MASK		(0x00000000)
#define MV_DP_MSG_CLIENT_RFU1_OFFS		(16)
#define MV_DP_MSG_CLIENT_RFU1_SET(v)		(((v) & MV_DP_MSG_CLIENT_RFU1_MASK) << MV_DP_MSG_CLIENT_RFU1_OFFS)
#define MV_DP_MSG_CLIENT_RFU1_GET(v)		(((v) >> MV_DP_MSG_CLIENT_RFU1_OFFS) & MV_DP_MSG_CLIENT_RFU1_MASK)


#define MV_DP_MSG_CLIENT_OD_WORD2		(2)
#define MV_DP_MSG_CLIENT_OD_OFFS		(0)
#define MV_DP_MSG_CLIENT_OD_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_CLIENT_OD_SET(v)		(((v) & MV_DP_MSG_CLIENT_OD_MASK) << MV_DP_MSG_CLIENT_OD_OFFS)
#define MV_DP_MSG_CLIENT_OD_GET(v)		(((v) >> MV_DP_MSG_CLIENT_OD_OFFS) & MV_DP_MSG_CLIENT_OD_MASK)

#define MV_DP_MSG_CLIENT_VLAN_WORD3		(3)
#define MV_DP_MSG_CLIENT_VLAN_OFFS		(0)
#define MV_DP_MSG_CLIENT_VLAN_MASK		(0x00000FFF)
#define MV_DP_MSG_CLIENT_VLAN_SET(v)		(((v) & MV_DP_MSG_CLIENT_VLAN_MASK) << MV_DP_MSG_CLIENT_VLAN_OFFS)
#define MV_DP_MSG_CLIENT_VLAN_GET(v)		(((v) >> MV_DP_MSG_CLIENT_VLAN_OFFS) & MV_DP_MSG_CLIENT_VLAN_MASK)

#define MV_DP_MSG_CLIENT_RFU2_WORD3		(3)	/*RFU no set/get */
#define MV_DP_MSG_CLIENT_RFU2_MASK		(0x0000F)
#define MV_DP_MSG_CLIENT_RFU2_OFFS		(12)
#define MV_DP_MSG_CLIENT_RFU2_SET(v)		(((v) & MV_DP_MSG_CLIENT_RFU2_MASK) << MV_DP_MSG_CLIENT_RFU2_OFFS)
#define MV_DP_MSG_CLIENT_RFU2_GET(v)		(((v) >> MV_DP_MSG_CLIENT_RFU2_OFFS) & MV_DP_MSG_CLIENT_RFU2_MASK)

#define MV_DP_MSG_CLIENT_PRIO_WORD3		(3)
#define MV_DP_MSG_CLIENT_PRIO_OFFS		(16)
#define MV_DP_MSG_CLIENT_PRIO_MASK		(0x0000001F)
#define MV_DP_MSG_CLIENT_PRIO_SET(v)		(((v) & MV_DP_MSG_CLIENT_PRIO_MASK) << MV_DP_MSG_CLIENT_PRIO_OFFS)
#define MV_DP_MSG_CLIENT_PRIO_GET(v)		(((v) >> MV_DP_MSG_CLIENT_PRIO_OFFS) & MV_DP_MSG_CLIENT_PRIO_MASK)

#define MV_DP_MSG_CLIENT_BRIDGE_WORD3		(3)
#define MV_DP_MSG_CLIENT_BRIDGE_OFFS		(21)
#define MV_DP_MSG_CLIENT_BRIDGE_MASK		(0x00000001)
#define MV_DP_MSG_CLIENT_BRIDGE_SET(v)		(((v) & MV_DP_MSG_CLIENT_BRIDGE_MASK) << MV_DP_MSG_CLIENT_BRIDGE_OFFS)
#define MV_DP_MSG_CLIENT_BRIDGE_GET(v)		(((v) >> MV_DP_MSG_CLIENT_BRIDGE_OFFS) & MV_DP_MSG_CLIENT_BRIDGE_MASK)

#define MV_DP_MSG_CLIENT_TUNNEL_WORD3		(3)
#define MV_DP_MSG_CLIENT_TUNNEL_OFFS		(22)
#define MV_DP_MSG_CLIENT_TUNNEL_MASK		(0x00000001)
#define MV_DP_MSG_CLIENT_TUNNEL_SET(v)		(((v) & MV_DP_MSG_CLIENT_TUNNEL_MASK) << MV_DP_MSG_CLIENT_TUNNEL_OFFS)
#define MV_DP_MSG_CLIENT_TUNNEL_GET(v)		(((v) >> MV_DP_MSG_CLIENT_TUNNEL_OFFS) & MV_DP_MSG_CLIENT_TUNNEL_MASK)

#define MV_DP_MSG_CLIENT_QCF_WORD3		(3)
#define MV_DP_MSG_CLIENT_QCF_OFFS		(23)
#define MV_DP_MSG_CLIENT_QCF_MASK		(0x00000001)
#define MV_DP_MSG_CLIENT_QCF_SET(v)		(((v) & MV_DP_MSG_CLIENT_QCF_MASK) << MV_DP_MSG_CLIENT_QCF_OFFS)
#define MV_DP_MSG_CLIENT_QCF_GET(v)		(((v) >> MV_DP_MSG_CLIENT_QCF_OFFS) & MV_DP_MSG_CLIENT_QCF_MASK)

#define MV_DP_MSG_CLIENT_RADIO_WORD3		(3)
#define MV_DP_MSG_CLIENT_RADIO_OFFS		(24)
#define MV_DP_MSG_CLIENT_RADIO_MASK		(0x00000003)
#define MV_DP_MSG_CLIENT_RADIO_SET(v)		(((v) & MV_DP_MSG_CLIENT_RADIO_MASK) << MV_DP_MSG_CLIENT_RADIO_OFFS)
#define MV_DP_MSG_CLIENT_RADIO_GET(v)		(((v) >> MV_DP_MSG_CLIENT_RADIO_OFFS) & MV_DP_MSG_CLIENT_RADIO_MASK)

#define MV_DP_MSG_CLIENT_MYMAC_WORD3		(3)
#define MV_DP_MSG_CLIENT_MYMAC_OFFS		(26)
#define MV_DP_MSG_CLIENT_MYMAC_MASK		(0x00000001)
#define MV_DP_MSG_CLIENT_MYMAC_SET(v)		(((v) & MV_DP_MSG_CLIENT_MYMAC_MASK) << MV_DP_MSG_CLIENT_MYMAC_OFFS)
#define MV_DP_MSG_CLIENT_MYMAC_GET(v)		(((v) >> MV_DP_MSG_CLIENT_MYMAC_OFFS) & MV_DP_MSG_CLIENT_MYMAC_MASK)

#define MV_DP_MSG_CLIENT_RFU3_WORD3		(3)	/*RFU no set/get */
#define MV_DP_MSG_CLIENT_RFU3_MASK		(0x00001)
#define MV_DP_MSG_CLIENT_RFU3_OFFS		(27)
#define MV_DP_MSG_CLIENT_RFU3_SET(v)		(((v) & MV_DP_MSG_CLIENT_RFU3_MASK) << MV_DP_MSG_CLIENT_RFU3_OFFS)
#define MV_DP_MSG_CLIENT_RFU3_GET(v)		(((v) >> MV_DP_MSG_CLIENT_RFU3_OFFS) & MV_DP_MSG_CLIENT_RFU3_MASK)

#define MV_DP_MSG_CLIENT_BSS_WORD3		(3)
#define MV_DP_MSG_CLIENT_BSS_OFFS		(28)
#define MV_DP_MSG_CLIENT_BSS_MASK		(0x0000000F)
#define MV_DP_MSG_CLIENT_BSS_SET(v)		(((v) & MV_DP_MSG_CLIENT_BSS_MASK) << MV_DP_MSG_CLIENT_BSS_OFFS)
#define MV_DP_MSG_CLIENT_BSS_GET(v)		(((v) >> MV_DP_MSG_CLIENT_BSS_OFFS) & MV_DP_MSG_CLIENT_BSS_MASK)
/**********Clients Fields END*****************************/

/*Client Index used in Client get request only*/
#define MV_DP_MSG_CLIENT_IND_WORD0		(0)
#define MV_DP_MSG_CLIENT_IND_OFFS		(0)
#define MV_DP_MSG_CLIENT_IND_MASK		(0x0000FFFF)
#define MV_DP_MSG_CLIENT_IND_SET(v)		(((v) & MV_DP_MSG_CLIENT_IND_MASK) << MV_DP_MSG_CLIENT_IND_OFFS)
#define MV_DP_MSG_CLIENT_IND_GET(v)		(((v) >> MV_DP_MSG_CLIENT_IND_OFFS) & MV_DP_MSG_CLIENT_IND_MASK)

/**********CLIENT MSG END********************************/

/***********PORT MSG*************************************/
/*Port Messages
*
* Sinlge messages only
* PORT_SET  request  -- ALL General+padding + ALL Fields per Port Type
* PORT_SET  reply    -- NONE
* PORT_GET  request  -- PORT_ID only + padding, single only
* PORT_GET  reply    -- ALL General + ALL Fields per Port Type
* PORT_DEL  request  -- PORT_ID only + padding, single only
* PORT_DEL  reply    -- NONE
* PORT_STATS_GET request -- PORT_ID only
* PORT_STATS_GET reply   -- ALL General + ALL STATS FIELDS
* PORT_STATS_RST request -- PORT_ID only
* PORT_STATS_RST reply   -- NONE
* Note: MAC addresses are not swapped as they are already in network order
*
* Bulk messages
* PORT_STATS_GET_BULK request -- PORT_IND only
* PORT_STATS_GET_BULK reply   -- ALL General + ALL STATS FIELDS
*
*GENERAL DATA*****************************************
* Port_id
* Port_type: 0..5 as in mv_dp_port_type
************************/

#define MV_DP_MSG_PORT_ID_WORD0			(0)
#define MV_DP_MSG_PORT_ID_OFFS			(0)
#define MV_DP_MSG_PORT_ID_MASK			(0x000000FF)
#define MV_DP_MSG_PORT_ID_SET(v)		(((v) & MV_DP_MSG_PORT_ID_MASK) << MV_DP_MSG_PORT_ID_OFFS)
#define MV_DP_MSG_PORT_ID_GET(v)		(((v) >> MV_DP_MSG_PORT_ID_OFFS) & MV_DP_MSG_PORT_ID_MASK)


#define MV_DP_MSG_PORT_INDEX_WORD0		(0)
#define MV_DP_MSG_PORT_INDEX_OFFS		(0)
#define MV_DP_MSG_PORT_INDEX_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_PORT_INDEX_SET(v)		(((v) & MV_DP_MSG_PORT_INDEX_MASK) << MV_DP_MSG_PORT_INDEX_OFFS)
#define MV_DP_MSG_PORT_INDEX_GET(v)		(((v) >> MV_DP_MSG_PORT_INDEX_OFFS) & MV_DP_MSG_PORT_INDEX_MASK)

/*private enum mv_dp_fw_port_type  used in set request and response to get to specify the type*/
#define MV_DP_MSG_PORT_TYPE_WORD0		(0)
#define MV_DP_MSG_PORT_TYPE_OFFS		(8)
#define MV_DP_MSG_PORT_TYPE_MASK		(0x000000FF)
#define MV_DP_MSG_PORT_TYPE_SET(v)		(((v) & MV_DP_MSG_PORT_TYPE_MASK) << MV_DP_MSG_PORT_TYPE_OFFS)
#define MV_DP_MSG_PORT_TYPE_GET(v)		(((v) >> MV_DP_MSG_PORT_TYPE_OFFS) & MV_DP_MSG_PORT_TYPE_MASK)

/*private enum mv_nss_dp_port_state_t  used in set request and response to get to specify the state*/
#define MV_DP_MSG_PORT_STATE_WORD0		(0)
#define MV_DP_MSG_PORT_STATE_OFFS		(16)
#define MV_DP_MSG_PORT_STATE_MASK		(0x000000FF)
#define MV_DP_MSG_PORT_STATE_SET(v)		(((v) & MV_DP_MSG_PORT_STATE_MASK) << MV_DP_MSG_PORT_STATE_OFFS)
#define MV_DP_MSG_PORT_STATE_GET(v)		(((v) >> MV_DP_MSG_PORT_STATE_OFFS) & MV_DP_MSG_PORT_STATE_MASK)

/*reserved*/
#define MV_DP_MSG_PORT_RFU_WORD0		(0)
#define MV_DP_MSG_PORT_RFU_OFFS			(24)
#define MV_DP_MSG_PORT_RFU_MASK			(0x000000FF)
#define MV_DP_MSG_PORT_RFU_SET(v)		(((v) & MV_DP_MSG_PORT_RFU_MASK) << MV_DP_MSG_PORT_RFU_OFFS)
#define MV_DP_MSG_PORT_RFU_GET(v)		(((v) >> MV_DP_MSG_PORT_RFU_OFFS) & MV_DP_MSG_PORT_RFU_MASK)

#define MV_DP_MSG_PORT_GET_TX_SIZE		(4)
#define MV_DP_MSG_PORT_GET_RX_SIZE		(MV_DP_MSG_SIZE_INVALID)

#define MV_DP_MSG_PORT_SET_TX_SIZE		(MV_DP_MSG_SIZE_INVALID)
#define MV_DP_MSG_PORT_SET_RX_SIZE		(0)

#define MV_DP_MSG_PORT_DEL_TX_SIZE		(4)
#define MV_DP_MSG_PORT_DEL_RX_SIZE		(0)


#define MV_DP_MSG_PORT_LINK_RX_SIZE		(0)
/****ETH PORT DATA***************************/
/*port_type=0*/

#define MV_DP_MSG_EPORT_SET_TX_SIZE		(16)
#define MV_DP_MSG_EPORT_SET_RX_SIZE		(0)

#define MV_DP_MSG_EPORT_GET_TX_SIZE		(4)
#define MV_DP_MSG_EPORT_GET_RX_SIZE		(16)

#define MV_DP_MSG_EPORT_DEL_TX_SIZE		(4)
#define MV_DP_MSG_EPORT_DEL_RX_SIZE		(0)

/************ETH Port Offsets***************************/
#define MV_DP_MSG_EPORT_OPTIONS_WORD1		(1)
#define MV_DP_MSG_EPORT_OPTIONS_OFFS		(0)
#define MV_DP_MSG_EPORT_OPTIONS_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_EPORT_OPTIONS_SET(v)		(((v) & MV_DP_MSG_EPORT_OPTIONS_MASK) << MV_DP_MSG_EPORT_OPTIONS_OFFS)
#define MV_DP_MSG_EPORT_OPTIONS_GET(v)		(((v) >> MV_DP_MSG_EPORT_OPTIONS_OFFS) & MV_DP_MSG_EPORT_OPTIONS_MASK)

#define MV_DP_MSG_EPORT_NVLAN_WORD2		(2)
#define MV_DP_MSG_EPORT_NVLAN_OFFS		(0)
#define MV_DP_MSG_EPORT_NVLAN_MASK		(0x0000FFFF)
#define MV_DP_MSG_EPORT_NVLAN_SET(v)		(((v) & MV_DP_MSG_EPORT_NVLAN_MASK) << MV_DP_MSG_EPORT_NVLAN_OFFS)
#define MV_DP_MSG_EPORT_NVLAN_GET(v)		(((v) >> MV_DP_MSG_EPORT_NVLAN_OFFS) & MV_DP_MSG_EPORT_NVLAN_MASK)

#define MV_DP_MSG_EPORT_VLAN_POL_WORD2		(2)
#define MV_DP_MSG_EPORT_VLAN_POL_OFFS		(16)
#define MV_DP_MSG_EPORT_VLAN_POL_MASK		(0x000000FF)
#define MV_DP_MSG_EPORT_VLAN_POL_SET(v)		(((v) & MV_DP_MSG_EPORT_VLAN_POL_MASK) << MV_DP_MSG_EPORT_VLAN_POL_OFFS)
#define MV_DP_MSG_EPORT_VLAN_POL_GET(v)		(((v) >> MV_DP_MSG_EPORT_VLAN_POL_OFFS) & MV_DP_MSG_EPORT_VLAN_POL_MASK)

#define MV_DP_MSG_EPORT_RFU1_WORD2		(2)
#define MV_DP_MSG_EPORT_RFU1_OFFS		(24)
#define MV_DP_MSG_EPORT_RFU1_MASK		(0x000000FF)

#define MV_DP_MSG_EPORT_TPID_WORD3		(3)
#define MV_DP_MSG_EPORT_TPID_OFFS		(0)
#define MV_DP_MSG_EPORT_TPID_MASK		(0x0000FFFF)
#define MV_DP_MSG_EPORT_TPID_SET(v)		(((v) & MV_DP_MSG_EPORT_TPID_MASK) << MV_DP_MSG_EPORT_TPID_OFFS)
#define MV_DP_MSG_EPORT_TPID_GET(v)		(((v) >> MV_DP_MSG_EPORT_TPID_OFFS) & MV_DP_MSG_EPORT_TPID_MASK)

#define MV_DP_MSG_EPORT_MTU_WORD3		(3)
#define MV_DP_MSG_EPORT_MTU_OFFS		(16)
#define MV_DP_MSG_EPORT_MTU_MASK		(0x0000FFFF)
#define MV_DP_MSG_EPORT_MTU_SET(v)		(((v) & MV_DP_MSG_EPORT_MTU_MASK) << MV_DP_MSG_EPORT_MTU_OFFS)
#define MV_DP_MSG_EPORT_MTU_GET(v)		(((v) >> MV_DP_MSG_EPORT_MTU_OFFS) & MV_DP_MSG_EPORT_MTU_MASK)
/****************PORT ETH MSG END************************/

/****************PORT CW MSG START***********************/
/*port type=3*/
#define MV_DP_MSG_CWPORT_SET_TX_SIZE		(88)
#define MV_DP_MSG_CWPORT_SET_RX_SIZE		(0)

#define MV_DP_MSG_CWPORT_GET_TX_SIZE		(4)
#define MV_DP_MSG_CWPORT_GET_RX_SIZE		(88)

#define MV_DP_MSG_CWPORT_DEL_TX_SIZE		(4)
#define MV_DP_MSG_CWPORT_DEL_RX_SIZE		(0)
/*IP addresses: IPv4 address is at 0, IPv6 is at word [0]..[3]
* say for 127.0.0.1 the w0 [127][0][0][1]
**/
/************CW Offsets****************************************/
#define MV_DP_MSG_CWPORT_RMAC_WORD1		(1)
#define MV_DP_MSG_CWPORT_RMAC_OFFS_B		(0)	/*Offset is in Bytes */
#define MV_DP_MSG_CWPORT_RMAC_SIZE		(6)

#define MV_DP_MSG_CWPORT_LMAC_WORD2		(2)
#define MV_DP_MSG_CWPORT_LMAC_OFFS_B		(2)	/*Offset is in Bytes */
#define MV_DP_MSG_CWPORT_LMAC_SIZE		(6)

#define MV_DP_MSG_CWPORT_BSSID_WORD4		(4)
#define MV_DP_MSG_CWPORT_BSSID_OFFS_B		(0)	/*Offset is in Bytes */
#define MV_DP_MSG_CWPORT_BSSID_SIZE		(6)

#define MV_DP_MSG_CWPORT_RFU1_WORD5		(5)
#define MV_DP_MSG_CWPORT_RFU1_OFFS_B		(2)	/*Offset is in Bytes */
#define MV_DP_MSG_CWPORT_RFU1_SIZE		(2)


#define MV_DP_MSG_CWPORT_RIP_WORD6		(6)
#define MV_DP_MSG_CWPORT_RIP_OFFS_B		(0)	/*Offset is in Bytes */
#define MV_DP_MSG_CWPORT_IP_SIZE		(16)

#define MV_DP_MSG_CWPORT_LIP_WORD10		(10)
#define MV_DP_MSG_CWPORT_LIP_OFFS_B		(0)	/*Offset is in Bytes */

#define MV_DP_MSG_CWPORT_TTL_WORD14		(14)
#define MV_DP_MSG_CWPORT_TTL_OFFS		(0)
#define MV_DP_MSG_CWPORT_TTL_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_CWPORT_TTL_SET(v)		(((v) & MV_DP_MSG_CWPORT_TTL_MASK) << MV_DP_MSG_CWPORT_TTL_OFFS)
#define MV_DP_MSG_CWPORT_TTL_GET(v)		(((v) >> MV_DP_MSG_CWPORT_TTL_OFFS) & MV_DP_MSG_CWPORT_TTL_MASK)

#define MV_DP_MSG_CWPORT_FLOW_LBL_WORD15	(15)
#define MV_DP_MSG_CWPORT_FLOW_LBL_OFFS		(0)
#define MV_DP_MSG_CWPORT_FLOW_LBL_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_CWPORT_FLOW_LBL_SET(v)	(((v) & MV_DP_MSG_CWPORT_FLOW_LBL_MASK) \
										<< MV_DP_MSG_CWPORT_FLOW_LBL_OFFS)
#define MV_DP_MSG_CWPORT_FLOW_LBL_GET(v)	(((v) >> MV_DP_MSG_CWPORT_FLOW_LBL_OFFS) \
										& MV_DP_MSG_CWPORT_FLOW_LBL_MASK)

#define MV_DP_MSG_CWPORT_DTLS_IND_WORD16	(16)
#define MV_DP_MSG_CWPORT_DTLS_IND_OFFS		(0)
#define MV_DP_MSG_CWPORT_DTLS_IND_MASK		(0x0000FFFF)
#define MV_DP_MSG_CWPORT_DTLS_IND_SET(v)	(((v) & MV_DP_MSG_CWPORT_DTLS_IND_MASK) \
										<< MV_DP_MSG_CWPORT_DTLS_IND_OFFS)
#define MV_DP_MSG_CWPORT_DTLS_IND_GET(v)	(((v) >> MV_DP_MSG_CWPORT_DTLS_IND_OFFS) \
										& MV_DP_MSG_CWPORT_DTLS_IND_MASK)

#define MV_DP_MSG_CWPORT_PMTU_WORD16		(16)
#define MV_DP_MSG_CWPORT_PMTU_OFFS		(16)
#define MV_DP_MSG_CWPORT_PMTU_MASK		(0x0000FFFF)
#define MV_DP_MSG_CWPORT_PMTU_SET(v)		(((v) & MV_DP_MSG_CWPORT_PMTU_MASK) << MV_DP_MSG_CWPORT_PMTU_OFFS)
#define MV_DP_MSG_CWPORT_PMTU_GET(v)		(((v) >> MV_DP_MSG_CWPORT_PMTU_OFFS) & MV_DP_MSG_CWPORT_PMTU_MASK)

#define MV_DP_MSG_CWPORT_RPORT_WORD17		(17)
#define MV_DP_MSG_CWPORT_RPORT_OFFS		(0)
#define MV_DP_MSG_CWPORT_RPORT_MASK		(0x0000FFFF)
#define MV_DP_MSG_CWPORT_RPORT_SET(v)		(((v) & MV_DP_MSG_CWPORT_RPORT_MASK) << MV_DP_MSG_CWPORT_RPORT_OFFS)
#define MV_DP_MSG_CWPORT_RPORT_GET(v)		(((v) >> MV_DP_MSG_CWPORT_RPORT_OFFS) & MV_DP_MSG_CWPORT_RPORT_MASK)

#define MV_DP_MSG_CWPORT_LPORT_WORD17		(17)
#define MV_DP_MSG_CWPORT_LPORT_OFFS		(16)
#define MV_DP_MSG_CWPORT_LPORT_MASK		(0x0000FFFF)
#define MV_DP_MSG_CWPORT_LPORT_SET(v)		(((v) & MV_DP_MSG_CWPORT_LPORT_MASK) << MV_DP_MSG_CWPORT_LPORT_OFFS)
#define MV_DP_MSG_CWPORT_LPORT_GET(v)		(((v) >> MV_DP_MSG_CWPORT_LPORT_OFFS) & MV_DP_MSG_CWPORT_LPORT_MASK)

#define MV_DP_MSG_CWPORT_UC_QOS_WORD18		(18)
#define MV_DP_MSG_CWPORT_UC_QOS_OFFS		(0)
#define MV_DP_MSG_CWPORT_UC_QOS_MASK		(0x000000FF)
#define MV_DP_MSG_CWPORT_UC_QOS_SET(v)		(((v) & MV_DP_MSG_CWPORT_UC_QOS_MASK) << MV_DP_MSG_CWPORT_UC_QOS_OFFS)
#define MV_DP_MSG_CWPORT_UC_QOS_GET(v)		(((v) >> MV_DP_MSG_CWPORT_UC_QOS_OFFS) & MV_DP_MSG_CWPORT_UC_QOS_MASK)

#define MV_DP_MSG_CWPORT_MC_QOS_WORD18		(18)
#define MV_DP_MSG_CWPORT_MC_QOS_OFFS		(8)
#define MV_DP_MSG_CWPORT_MC_QOS_MASK		(0x000000FF)
#define MV_DP_MSG_CWPORT_MC_QOS_SET(v)		(((v) & MV_DP_MSG_CWPORT_MC_QOS_MASK) << MV_DP_MSG_CWPORT_MC_QOS_OFFS)
#define MV_DP_MSG_CWPORT_MC_QOS_GET(v)		(((v) >> MV_DP_MSG_CWPORT_MC_QOS_OFFS) & MV_DP_MSG_CWPORT_MC_QOS_MASK)

#define MV_DP_MSG_CWPORT_RFU2_WORD18		(18)
#define MV_DP_MSG_CWPORT_RFU3_OFFS		(16)
#define MV_DP_MSG_CWPORT_RFU3_MASK		(0x000000FF)

#define MV_DP_MSG_CWPORT_CSUM_WORD18		(18)
#define MV_DP_MSG_CWPORT_CSUM_OFFS		(24)
#define MV_DP_MSG_CWPORT_CSUM_MASK		(0x000000FF)
#define MV_DP_MSG_CWPORT_CSUM_SET(v)		(((v) & MV_DP_MSG_CWPORT_CSUM_MASK) << MV_DP_MSG_CWPORT_CSUM_OFFS)
#define MV_DP_MSG_CWPORT_CSUM_GET(v)		(((v) >> MV_DP_MSG_CWPORT_CSUM_OFFS) & MV_DP_MSG_CWPORT_CSUM_MASK)


#define MV_DP_MSG_CWPORT_PORT_ID_WORD19		(19)
#define MV_DP_MSG_CWPORT_PORT_ID_OFFS		(0)
#define MV_DP_MSG_CWPORT_PORT_ID_MASK		(0x000000FF)
#define MV_DP_MSG_CWPORT_PORT_ID_SET(v)		(((v) & MV_DP_MSG_CWPORT_PORT_ID_MASK) \
										<< MV_DP_MSG_CWPORT_PORT_ID_OFFS)
#define MV_DP_MSG_CWPORT_PORT_ID_GET(v)		(((v) >> MV_DP_MSG_CWPORT_PORT_ID_OFFS) \
										& MV_DP_MSG_CWPORT_PORT_ID_MASK)
#define MV_DP_MSG_CWPORT_OPTIONS_WORD19		(19)
#define MV_DP_MSG_CWPORT_OPTIONS_OFFS		(8)
#define MV_DP_MSG_CWPORT_OPTIONS_MASK		(0x000000FF)
#define MV_DP_MSG_CWPORT_OPTIONS_SET(v)		(((v) & MV_DP_MSG_CWPORT_OPTIONS_MASK) \
										<< MV_DP_MSG_CWPORT_OPTIONS_OFFS)
#define MV_DP_MSG_CWPORT_OPTIONS_GET(v)		(((v) >> MV_DP_MSG_CWPORT_OPTIONS_OFFS) \
										& MV_DP_MSG_CWPORT_OPTIONS_MASK)

/*could grow to 16bit if needed*/
#define MV_DP_MSG_CWPORT_L4_PROTO_WORD19	(19)
#define MV_DP_MSG_CWPORT_L4_PROTO_OFFS		(16)
#define MV_DP_MSG_CWPORT_L4_PROTO_MASK		(0x000000FF)
#define MV_DP_MSG_CWPORT_L4_PROTO_SET(v)	(((v) & MV_DP_MSG_CWPORT_L4_PROTO_MASK) \
										<< MV_DP_MSG_CWPORT_L4_PROTO_OFFS)
#define MV_DP_MSG_CWPORT_L4_PROTO_GET(v)	(((v) >> MV_DP_MSG_CWPORT_L4_PROTO_OFFS) \
										& MV_DP_MSG_CWPORT_L4_PROTO_MASK)
#define MV_DP_MSG_CWPORT_IPVER_WORD19		(19)
#define MV_DP_MSG_CWPORT_IPVER_OFFS		(24)
#define MV_DP_MSG_CWPORT_IPVER_MASK		(0x000000FF)

#define MV_DP_MSG_CWPORT_IPVER_SET(v)		(((v) & MV_DP_MSG_CWPORT_IPVER_MASK) << MV_DP_MSG_CWPORT_IPVER_OFFS)
#define MV_DP_MSG_CWPORT_IPVER_GET(v)		(((v) >> MV_DP_MSG_CWPORT_IPVER_OFFS) & MV_DP_MSG_CWPORT_IPVER_MASK)


#define MV_DP_MSG_CWPORT_L4_PRT_HASH_WORD20	(20)
#define MV_DP_MSG_CWPORT_L4_PRT_HASH_OFFS	(0)
#define MV_DP_MSG_CWPORT_L4_PRT_HASH_MASK	(0xFFFFFFFF)

#define MV_DP_MSG_CWPORT_L4_PRT_HASH_SET(v)	(((v) & MV_DP_MSG_CWPORT_L4_PRT_HASH_MASK) \
										<< MV_DP_MSG_CWPORT_L4_PRT_HASH_OFFS)
#define MV_DP_MSG_CWPORT_L4_PRT_HASH_GET(v)	(((v) >> MV_DP_MSG_CWPORT_L4_PRT_HASH_OFFS) \
										& MV_DP_MSG_CWPORT_L4_PRT_HASH_MASK)


#define MV_DP_MSG_CWPORT_VLAN_ID_WORD21		(21)
#define MV_DP_MSG_CWPORT_VLAN_ID_OFFS		(0)
#define MV_DP_MSG_CWPORT_VLAN_ID_MASK		(0x0000FFFF)
#define MV_DP_MSG_CWPORT_VLAN_ID_SET(v)		(((v) & MV_DP_MSG_CWPORT_VLAN_ID_MASK) \
										<< MV_DP_MSG_CWPORT_VLAN_ID_OFFS)
#define MV_DP_MSG_CWPORT_VLAN_ID_GET(v)		(((v) >> MV_DP_MSG_CWPORT_VLAN_ID_OFFS) \
										& MV_DP_MSG_CWPORT_VLAN_ID_MASK)

#define MV_DP_MSG_CWPORT_L4_TX_BITS_WORD21	(21)
#define MV_DP_MSG_CWPORT_L4_TX_BITS_OFFS	(16)
#define MV_DP_MSG_CWPORT_L4_TX_BITS_MASK	(0x000000FF)
#define MV_DP_MSG_CWPORT_L4_TX_BITS_SET(v)	(((v) & MV_DP_MSG_CWPORT_L4_TX_BITS_MASK) \
									<< MV_DP_MSG_CWPORT_L4_TX_BITS_OFFS)
#define MV_DP_MSG_CWPORT_L4_TX_BITS_GET(v)	(((v) >> MV_DP_MSG_CWPORT_L4_TX_BITS_OFFS) \
									& MV_DP_MSG_CWPORT_L4_TX_BITS_MASK)

#define MV_DP_MSG_CWPORT_L4_RX_BITS_WORD21	(21)
#define MV_DP_MSG_CWPORT_L4_RX_BITS_OFFS	(24)
#define MV_DP_MSG_CWPORT_L4_RX_BITS_MASK	(0x000000FF)
#define MV_DP_MSG_CWPORT_L4_RX_BITS_SET(v)	(((v) & MV_DP_MSG_CWPORT_L4_RX_BITS_MASK) \
									<< MV_DP_MSG_CWPORT_L4_RX_BITS_OFFS)
#define MV_DP_MSG_CWPORT_L4_RX_BITS_GET(v)	(((v) >> MV_DP_MSG_CWPORT_L4_RX_BITS_OFFS) \
									& MV_DP_MSG_CWPORT_L4_RX_BITS_MASK)


/****************PORT CW MSG END*****************************/

/****************PORT ETH LAG MSG START**********************/
/*port_type=1*/

#define MV_DP_MSG_LAGPORT_SET_TX_SIZE		(12)
#define MV_DP_MSG_LAGPORT_SET_RX_SIZE		(0)

#define MV_DP_MSG_LAGPORT_GET_TX_SIZE		(4)
#define MV_DP_MSG_LAGPORT_GET_RX_SIZE		(12)

#define MV_DP_MSG_LAGPORT_DEL_TX_SIZE		(4)
#define MV_DP_MSG_LAGPORT_DEL_RX_SIZE		(0)

/************LAG Offsets**************************************/

#define MV_DP_MSG_LAGPORT_LINKS_WORD1		(1)
#define MV_DP_MSG_LAGPORT_LINKS_OFFS		(0)
#define MV_DP_MSG_LAGPORT_LINKS_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_LAGPORT_LINKS_SET(v)		(((v) & MV_DP_MSG_LAGPORT_LINKS_MASK) << MV_DP_MSG_LAGPORT_LINKS_OFFS)
#define MV_DP_MSG_LAGPORT_LINKS_GET(v)		(((v) >> MV_DP_MSG_LAGPORT_LINKS_OFFS) & MV_DP_MSG_LAGPORT_LINKS_MASK)

#define MV_DP_MSG_LAGPORT_HASH_PROF_WORD2	(2)
#define MV_DP_MSG_LAGPORT_HASH_PROF_OFFS	(0)
#define MV_DP_MSG_LAGPORT_HASH_PROF_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_LAGPORT_HASH_PROF_SET(v)	(((v) & MV_DP_MSG_LAGPORT_HASH_PROF_MASK) \
										<< MV_DP_MSG_LAGPORT_HASH_PROF_OFFS)
#define MV_DP_MSG_LAGPORT_HASH_PROF_GET(v)	(((v) >> MV_DP_MSG_LAGPORT_HASH_PROF_OFFS) \
										& MV_DP_MSG_LAGPORT_HASH_PROF_MASK)

/************LAG PORT END**************************************/

/************PORT WLAN MSG START**********************/
/*port_type=5*/
#define MV_DP_MSG_WLANPORT_SET_TX_SIZE		(8)
#define MV_DP_MSG_WLANPORT_SET_RX_SIZE		(0)

#define MV_DP_MSG_WLANPORT_GET_TX_SIZE		(4)
#define MV_DP_MSG_WLANPORT_GET_RX_SIZE		(8)

#define MV_DP_MSG_WLANPORT_DEL_TX_SIZE		(4)
#define MV_DP_MSG_WLANPORT_DEL_RX_SIZE		(0)

/************PORT WLAN MSG Offsets********************/
#define MV_DP_MSG_WLANPORT_RADIO_ID_WORD1	(1)
#define MV_DP_MSG_WLANPORT_RADIO_ID_OFFS	(0)
#define MV_DP_MSG_WLANPORT_RADIO_ID_MASK	(0x000000FF)
#define MV_DP_MSG_WLANPORT_RADIO_ID_SET(v)	(((v) & MV_DP_MSG_WLANPORT_RADIO_ID_MASK) \
									<< MV_DP_MSG_WLANPORT_RADIO_ID_OFFS)
#define MV_DP_MSG_WLANPORT_RADIO_ID_GET(v)	(((v) >> MV_DP_MSG_WLANPORT_RADIO_ID_OFFS) \
									& MV_DP_MSG_WLANPORT_RADIO_ID_MASK)

#define MV_DP_MSG_WLANPORT_RFU_WORD1		(1)
#define MV_DP_MSG_WLANPORT_RFU_OFFS		(8)
#define MV_DP_MSG_WLANPORT_RFU_MASK		(0x00FFFFFF)
/************PORT WLAN END****************************/

/************PORT CPU MSG START**********************/
/*port_type=2*/
#define MV_DP_MSG_CPUPORT_SET_TX_SIZE		(12)
#define MV_DP_MSG_CPUPORT_SET_RX_SIZE		(0)

#define MV_DP_MSG_CPUPORT_GET_TX_SIZE		(4)
#define MV_DP_MSG_CPUPORT_GET_RX_SIZE		(12)

#define MV_DP_MSG_CPUPORT_DEL_TX_SIZE		(4)
#define MV_DP_MSG_CPUPORT_DEL_RX_SIZE		(0)

/************PORT CPU MSG Offsets********************/


#define MV_DP_MSG_CPUPORT_BITMASK_WORD1		(1)
#define MV_DP_MSG_CPUPORT_BITMASK_OFFS		(0)
#define MV_DP_MSG_CPUPORT_BITMASK_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_CPUPORT_BITMASK_SET(v)	(((v) & MV_DP_MSG_CPUPORT_BITMASK_MASK) \
									<< MV_DP_MSG_CPUPORT_BITMASK_OFFS)
#define MV_DP_MSG_CPUPORT_BITMASK_GET(v)	(((v) >> MV_DP_MSG_CPUPORT_BITMASK_OFFS) \
									& MV_DP_MSG_CPUPORT_BITMASK_MASK)

#define MV_DP_MSG_CPUPORT_HASH_PROF_WORD2	(2)
#define MV_DP_MSG_CPUPORT_HASH_PROF_OFFS	(0)
#define MV_DP_MSG_CPUPORT_HASH_PROF_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_CPUPORT_HASH_PROF_SET(v)	(((v) & MV_DP_MSG_CPUPORT_HASH_PROF_MASK) \
									<< MV_DP_MSG_CPUPORT_HASH_PROF_OFFS)
#define MV_DP_MSG_CPUPORT_HASH_PROF_GET(v)	(((v) >> MV_DP_MSG_CPUPORT_HASH_PROF_OFFS) \
									& MV_DP_MSG_CPUPORT_HASH_PROF_MASK)

/************PORT CPU END****************************/

/************PORT STATS START***************************/
/*
*Single Requests Only
* PORT_STATS_GET request -- port_id only + padding, single only
* PORT_STATS_GET reply   -- ALL General (port_id, type, pad) + ALL STATS Fields (start at W1)
* PORT_STATS_RST request -- port_id only + padding, single only
* PORT_STATS_RST reply   -- NONE
*
* Bulk Requests:* how index is derived?
* PORT_STATS_GET_BULK request -- Extension Header if needed, index only + padding after extension hdr!
* PORT_STATS_GET_BULK reply   -- n's stats is at BULK_RX_SIZE * n zero base byte offset
**/

#define MV_DP_MSG_PORT_STATS_GET_TX_SIZE	(4)
#define MV_DP_MSG_PORT_STATS_GET_RX_SIZE	(52)

#define MV_DP_MSG_PORT_STATS_GET_BULK_TX_SIZE	(4)
#define MV_DP_MSG_PORT_STATS_GET_BULK_RX_SIZE	(52)	/*for a single entry */

#define MV_DP_MSG_PORT_STATS_RST_TX_SIZE	(4)	/*data only+ ext if needed*/
#define MV_DP_MSG_PORT_STATS_RST_RX_SIZE	(0)

/************PORT STATS Field OFFSETs*********************/

#define MV_DP_MSG_PORT_STAT_RX_PKTS_WORD1	(1)
#define MV_DP_MSG_PORT_STAT_RX_PKTS_OFFS	(0)
#define MV_DP_MSG_PORT_STAT_RX_PKTS_SIZE	(8)

#define MV_DP_MSG_PORT_STAT_RX_ERR_WORD3	(3)
#define MV_DP_MSG_PORT_STAT_RX_ERR_OFFS		(0)
#define MV_DP_MSG_PORT_STAT_RX_ERR_SIZE		(8)

#define MV_DP_MSG_PORT_STAT_TX_PKTS_WORD5	(5)
#define MV_DP_MSG_PORT_STAT_TX_PKTS_OFFS	(0)
#define MV_DP_MSG_PORT_STAT_TX_PKTS_SIZE	(8)

#define MV_DP_MSG_PORT_STAT_TX_ERR_WORD7	(7)
#define MV_DP_MSG_PORT_STAT_TX_ERR_OFFS		(0)
#define MV_DP_MSG_PORT_STAT_TX_ERR_SIZE		(8)

#define MV_DP_MSG_PORT_STAT_RX_OCTS_WORD9	(9)
#define MV_DP_MSG_PORT_STAT_RX_OCTS_OFFS	(0)
#define MV_DP_MSG_PORT_STAT_RX_OCTS_SIZE	(8)

#define MV_DP_MSG_PORT_STAT_TX_OCTS_WORD11	(11)
#define MV_DP_MSG_PORT_STAT_TX_OCTS_OFFS	(0)
#define MV_DP_MSG_PORT_STAT_TX_OCTS_SIZE	(8)
/************PORT STATS MSG END***************************/
/****************PORT MSG END*****************************/

/************VLAN CFG MSG START***************************/
/*
*VLAN_CFG_SET request -- ALL FIELDS, multiple requests same as single request,
*			n's starts at VLAN_SET_TX_SIZE*n, extension header if needed
*VLAN_CFG_SET reply   -- NONE
*
*VLAN_CFG_GET request -- INDEX
*			 Extension hdr in/out if needed, VLAN_IDs: after ext header or in IN buffer
*VLAN_CFG_GET reply   -- ALL FIELDS, multiple replies:
*			n's record starts at byte (n * GET_RX_SIZE) [zero based] (either in CFH or OUT buffer)
*
*VLAN_CFG_DEL request -- VLAN_ID
*			multiple requests VLAN_ID n's is at byte offset VLAN_GET_TX_SIZE * n [zero based]
*			 Extension hdr in/out if needed, VLAN_IDs: after ext header or in IN buffer
*VLAN_CFG_DEL reply   -- None
*
*
*VLAN_CFG_DEL_ALL request -- None
*VLAN_CFG_DEL_ALL reply   -- None
*
*VLAN_CFG_GET_BY_ID request -- VLAN_ID
*VLAN_CFG_GET_ID    reply   -- ALL FIELDS
*
*/

#define MV_DP_MSG_VLAN_CFG_SET_TX_SIZE		(8)
#define MV_DP_MSG_VLAN_CFG_SET_RX_SIZE		(0)

#define MV_DP_MSG_VLAN_CFG_GET_TX_SIZE		(4)	/*single key to be rounded to a word boundary */
#define MV_DP_MSG_VLAN_CFG_GET_RX_SIZE		(8)

#define MV_DP_MSG_VLAN_CFG_GET_BY_ID_TX_SIZE	(4)	/*single key to be rounded to a word boundary */
#define MV_DP_MSG_VLAN_CFG_GET_BY_ID_RX_SIZE	(8)


#define MV_DP_MSG_VLAN_CFG_DEL_TX_SIZE		(4)	/*single key to be rounded to a word boundary */
#define MV_DP_MSG_VLAN_CFG_DEL_RX_SIZE		(0)

/************VLAN CFG Offsets**************************/
#define MV_DP_MSG_VLAN_CFG_VLAN_ID_WORD0	(0)
#define MV_DP_MSG_VLAN_CFG_VLAN_ID_OFFS		(0)
#define MV_DP_MSG_VLAN_CFG_VLAN_ID_MASK		(0x0000FFFF)
#define MV_DP_MSG_VLAN_CFG_VLAN_ID_SET(v)	(((v) & MV_DP_MSG_VLAN_CFG_VLAN_ID_MASK) \
										<< MV_DP_MSG_VLAN_CFG_VLAN_ID_OFFS)
#define MV_DP_MSG_VLAN_CFG_VLAN_ID_GET(v)	(((v) >> MV_DP_MSG_VLAN_CFG_VLAN_ID_OFFS) \
										& MV_DP_MSG_VLAN_CFG_VLAN_ID_MASK)

#define MV_DP_MSG_VLAN_CFG_INDEX_WORD0		(0)
#define MV_DP_MSG_VLAN_CFG_INDEX_OFFS		(0)
#define MV_DP_MSG_VLAN_CFG_INDEX_MASK		(0x0000FFFF)
#define MV_DP_MSG_VLAN_CFG_INDEX_SET(v)		(((v) & MV_DP_MSG_VLAN_CFG_INDEX_MASK) \
										<< MV_DP_MSG_VLAN_CFG_INDEX_OFFS)
#define MV_DP_MSG_VLAN_CFG_INDEXD_GET(v)	(((v) >> MV_DP_MSG_VLAN_CFG_INDEX_OFFS) \
										& MV_DP_MSG_VLAN_CFG_INDEX_MASK)

#define MV_DP_MSG_VLAN_CFG_RFU1_WORD0		(0)
#define MV_DP_MSG_VLAN_CFG_RFU1_OFFS		(16)
#define MV_DP_MSG_VLAN_CFG_RFU1_MASK		(0x0000FFFF)

#define MV_DP_MSG_VLAN_CFG_UC_QOS_POL_WORD1	(1)
#define MV_DP_MSG_VLAN_CFG_UC_QOS_POL_OFFS	(0)
#define MV_DP_MSG_VLAN_CFG_UC_QOS_POL_MASK	(0x000000FF)
#define MV_DP_MSG_VLAN_CFG_UC_QOS_POL_SET(v)	(((v) & MV_DP_MSG_VLAN_CFG_UC_QOS_POL_MASK) \
										<< MV_DP_MSG_VLAN_CFG_UC_QOS_POL_OFFS)
#define MV_DP_MSG_VLAN_CFG_UC_QOS_POL_GET(v)	(((v) >> MV_DP_MSG_VLAN_CFG_UC_QOS_POL_OFFS) \
										& MV_DP_MSG_VLAN_CFG_UC_QOS_POL_MASK)

#define MV_DP_MSG_VLAN_CFG_MC_QOS_POL_WORD1	(1)
#define MV_DP_MSG_VLAN_CFG_MC_QOS_POL_OFFS	(8)
#define MV_DP_MSG_VLAN_CFG_MC_QOS_POL_MASK	(0x000000FF)
#define MV_DP_MSG_VLAN_CFG_MC_QOS_POL_SET(v)	(((v) & MV_DP_MSG_VLAN_CFG_MC_QOS_POL_MASK) \
										<< MV_DP_MSG_VLAN_CFG_MC_QOS_POL_OFFS)
#define MV_DP_MSG_VLAN_CFG_MC_QOS_POL_GET(v)	(((v) >> MV_DP_MSG_VLAN_CFG_MC_QOS_POL_OFFS) \
										& MV_DP_MSG_VLAN_CFG_MC_QOS_POL_MASK)

#define MV_DP_MSG_VLAN_CFG_PORTS_MASK_WORD1	(1)
#define MV_DP_MSG_VLAN_CFG_PORTS_MASK_OFFS	(16)
#define MV_DP_MSG_VLAN_CFG_PORTS_MASK_MASK	(0x000000FF)
#define MV_DP_MSG_VLAN_CFG_PORTS_MASK_SET(v)	(((v) & MV_DP_MSG_VLAN_CFG_PORTS_MASK_MASK) \
										<< MV_DP_MSG_VLAN_CFG_PORTS_MASK_OFFS)
#define MV_DP_MSG_VLAN_CFG_PORTS_MASK_GET(v)	(((v) >> MV_DP_MSG_VLAN_CFG_PORTS_MASK_OFFS) \
										& MV_DP_MSG_VLAN_CFG_PORTS_MASK_MASK)

#define MV_DP_MSG_VLAN_CFG_RFU2_WORD1		(1)
#define MV_DP_MSG_VLAN_CFG_RFU2_OFFS		(24)
#define MV_DP_MSG_VLAN_CFG_RFU2_MASK		(0x000000FF)
/**************VLAN MSG END*****************************/

/************EXCEPTIONS START***************************/
/*
*EXCEPT_CFG_SET request   -- ALL EXCEPT_CFG Fields
*EXCEPT_CFG_SET reply     -- NONE
*
*EXCEPT_CFG_GET request   -- NONE
*EXCEPT_CFG_GET reply     -- ALL EXCEPT_CFG Fields
*
*EXCEPT_STATS_GET request -- Extension Buffer with OUT pointer(s),
*			     PORT_ID + (padding) at W0 of the message following the Extension header
*EXCEPT_STATS_GET reply   -- Extension OUT Buffers: PORT_ID + padding at
*				word0 and 32x8Byte values in words 1..64
*
*EXCEPT_STATS_RST request -- PORT_ID only + padding -1 for ALL
*EXCEPT_STATS_RST reply   -- NONE
*
**
*EXCEPT_STATS_GET_BULK request -- Extension OUT header with appropriate number of buffers
*				  INDEX in W0 (count is in CFH header up to 4k) following the extension header
*EXCEPT_STATS_GET_BULK reply   -- PORT_ID + padding in W0 and Count of 8Byte values
*				in words 1..(count*2) of the OUT buffer
******/

#define MV_DP_MSG_EXCEPT_CFG_SET_TX_SIZE	(8)
#define MV_DP_MSG_EXCEPT_CFG_SET_RX_SIZE	(0)

#define MV_DP_MSG_EXCEPT_CFG_GET_TX_SIZE	(0)
#define MV_DP_MSG_EXCEPT_CFG_GET_RX_SIZE	(8)

#define MV_DP_MSG_EXCEPT_STATS_GET_TX_SIZE	(4)	/*one entry of out buffer */
#define MV_DP_MSG_EXCEPT_STATS_GET_RX_SIZE	(8+256)

#define MV_DP_MSG_EXCEPT_STATS_GET_BULK_TX_SIZE	(4)	/*one entry of out buffer */
#define MV_DP_MSG_EXCEPT_STATS_GET_BULK_RX_SIZE	(8+256)

#define MV_DP_MSG_EXCEPT_STATS_RST_TX_SIZE	(4)
#define MV_DP_MSG_EXCEPT_STATS_RST_RX_SIZE	(0)

/************EXCEPTIONS OFFSETS Offsets**************************/
#define MV_DP_MSG_EXCEPT_CFG_POINTS_WORD0	(0)
#define MV_DP_MSG_EXCEPT_CFG_POINTS_OFFS	(0)
#define MV_DP_MSG_EXCEPT_CFG_POINTS_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_EXCEPT_CFG_POINTS_SET(v)	(((v) & MV_DP_MSG_EXCEPT_CFG_POINTS_MASK) \
									<< MV_DP_MSG_EXCEPT_CFG_POINTS_OFFS)
#define MV_DP_MSG_EXCEPT_CFG_POINTS_GET(v)	(((v) >> MV_DP_MSG_EXCEPT_CFG_POINTS_OFFS) \
									& MV_DP_MSG_EXCEPT_CFG_POINTS_MASK)

#define MV_DP_MSG_EXCEPT_CFG_PRIO_WORD1		(1)
#define MV_DP_MSG_EXCEPT_CFG_PRIO_OFFS		(0)
#define MV_DP_MSG_EXCEPT_CFG_PRIO_MASK		(0x000000FF)
#define MV_DP_MSG_EXCEPT_CFG_PRIO_SET(v)	(((v) & MV_DP_MSG_EXCEPT_CFG_PRIO_MASK) \
									<< MV_DP_MSG_EXCEPT_CFG_PRIO_OFFS)
#define MV_DP_MSG_EXCEPT_CFG_PRIO_GET(v)	(((v) >> MV_DP_MSG_EXCEPT_CFG_PRIO_OFFS) \
									& MV_DP_MSG_EXCEPT_CFG_PRIO_MASK)

#define MV_DP_MSG_EXCEPT_RFU1_WORD1		(1)
#define MV_DP_MSG_EXCEPT_RFU1_OFFS		(24)
#define MV_DP_MSG_EXCEPT_RFU1_MASK		(0x00FFFFFF)


#define MV_DP_MSG_EXCEPT_STATS_PORT_ID_WORD0	(0)
#define MV_DP_MSG_EXCEPT_STATS_PORT_ID_OFFS	(0)
#define MV_DP_MSG_EXCEPT_STATS_PORT_ID_MASK	(0x000000FF)
#define MV_DP_MSG_EXCEPT_STATS_PORT_ID_SET(v)	(((v) & MV_DP_MSG_EXCEPT_STATS_PORT_ID_MASK) \
									<< MV_DP_MSG_EXCEPT_STATS_PORT_ID_OFFS)
#define MV_DP_MSG_EXCEPT_STATS_PORT_ID_GET(v)	(((v) >> MV_DP_MSG_EXCEPT_STATS_PORT_ID_OFFS) \
									& MV_DP_MSG_EXCEPT_STATS_PORT_ID_MASK)

#define MV_DP_MSG_EXCEPT_STATS_RFU_WORD0	(0)
#define MV_DP_MSG_EXCEPT_STATS_RFU_OFFS		(8)
#define MV_DP_MSG_EXCEPT_STATS_RFU_MASK		(0x00FFFFFF)

/*start of the counters array of 32x8bytes */
#define MV_DP_MSG_EXCEPT_STATS_OFFS_W		(2)
#define MV_DP_MSG_EXCEPT_STATS_OFFS_B		(MV_DP_MSG_EXCEPT_STATS_OFFS_W * 4)

#define MV_DP_MSG_EXCEPT_STATS_RFU_WORD1	(1)

#define MV_DP_MSG_EXCEPT_STATS_INDEX_WORD0	(0)
#define MV_DP_MSG_EXCEPT_STATS_INDEX_OFFS	(0)
#define MV_DP_MSG_EXCEPT_STATS_INDEX_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_EXCEPT_STATS_INDEX_SET(v)	(((v) & MV_DP_MSG_EXCEPT_STATS_INDEX_MASK) \
									<< MV_DP_MSG_EXCEPT_STATS_INDEX_OFFS)
#define MV_DP_MSG_EXCEPT_STATS_INDEX_GET(v)	(((v) >> MV_DP_MSG_EXCEPT_STATS_INDEX_OFFS) \
									& MV_DP_MSG_EXCEPT_STATS_INDEX_MASK)

/**************EXCEPTIONS MSG END*************************************/


/************ PORT DST SET MSG START***************************/
/*
* Note: Message supports mv_nss_dp_init
*
*PORT_DST_SET_CFG request -- DST_PORT_ID
*
*PORT_DST_SET_CFG reply   -- NONE
*/

#define MV_DP_MSG_PORT_DST_SET_CFG_TX_SIZE		(4)
#define MV_DP_MSG_PORT_DST_SET_CFG_RX_SIZE		(0)

/************INIT PORT DST CFG Offsets**************************/
#define MV_DP_MSG_PORT_DST_PORT_ID_WORD0	(0)
#define MV_DP_MSG_PORT_DST_PORT_ID_OFFS		(0)
#define MV_DP_MSG_PORT_DST_PORT_ID_MASK		(0xFF)
#define MV_DP_MSG_PORT_DST_PORT_ID_SET(v)	(((v) & MV_DP_MSG_PORT_DST_PORT_ID_MASK) \
									<< MV_DP_MSG_PORT_DST_PORT_ID_OFFS)
#define MV_DP_MSG_PORT_DST_PORT_ID_GET(v)	(((v) >> MV_DP_MSG_PORT_DST_PORT_ID_OFFS) \
									& MV_DP_MSG_PORT_DST_PORT_ID_MASK)

#define MV_DP_MSG_PORT_DST_SET_CFG_RFU_WORD0	(0)
#define MV_DP_MSG_PORT_DST_SET_CFG_RFU_OFFS	(8)
#define MV_DP_MSG_PORT_DST_SET_CFG_RFU_MASK	(0xFFFFFF)

/**************INIT PORT DST CFG END*****************************/

/**************QOS_ POLICY COMMON*****************************/
/* EGRESS and INGRESS POLICY GET AND SEND CONTAIN u8 policy ID
*/

#define MV_DP_MSG_QOS_POLICY_ID_WORD0		(0)
#define MV_DP_MSG_QOS_POLICY_ID_OFFS		(0)
#define MV_DP_MSG_QOS_POLICY_ID_MASK		(0x000000FF)
#define MV_DP_MSG_QOS_POLICY_ID_SET(v)		(((v) & MV_DP_MSG_QOS_POLICY_ID_MASK) \
									<< MV_DP_MSG_QOS_POLICY_ID_OFFS)
#define MV_DP_MSG_QOS_POLICY_ID_GET(v)		(((v) >> MV_DP_MSG_QOS_POLICY_ID_OFFS) \
									& MV_DP_MSG_QOS_POLICY_ID_MASK)

#define MV_DP_MSG_QOS_POLICY_RFU1_WORD0		(0)
#define MV_DP_MSG_QOS_POLICY_RFU1_OFFS		(8)
#define MV_DP_MSG_QOS_POLICY_RFU1_MASK		(0x00FFFFFF)

/**************QOS_ POLICY COMMON END*****************************/

/************QUEUE CONFIG COMMON***********************************
*QUEUE_CFG_SET request   -- QID, POLICER CIR, EIR
*QUEUE_CFG_SET reply     -- NONE
*
*QUEUE_CFG_GET request   -- QID
*QUEUE_CFG_GET reply     -- QID, POLICER CIR, EIR
**********************************************************************/
#define MV_DP_MSG_QUEUE_CFG_SET_TX_SIZE			(24)
#define MV_DP_MSG_QUEUE_CFG_SET_RX_SIZE			(0)

#define MV_DP_MSG_QUEUE_CFG_GET_TX_SIZE			(4)
#define MV_DP_MSG_QUEUE_CFG_GET_RX_SIZE			(24)

/**********************************************************************/

#define MV_DP_MSG_QUEUE_CFG_QUEUE_ID_WORD0		(0)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_ID_OFFS		(0)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_ID_MASK		(0x000000FF)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_ID_SET(v)		(((v) & MV_DP_MSG_QUEUE_CFG_QUEUE_ID_MASK) \
									<< MV_DP_MSG_QUEUE_CFG_QUEUE_ID_OFFS)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_ID_GET(v)		(((v) >> MV_DP_MSG_QUEUE_CFG_QUEUE_ID_OFFS) \
									& MV_DP_MSG_QUEUE_CFG_QUEUE_ID_MASK)

#define MV_DP_MSG_QUEUE_CFG_POLICER_CIR_WORD1		(1)
#define MV_DP_MSG_QUEUE_CFG_POLICER_CIR_OFFS		(0)
#define MV_DP_MSG_QUEUE_CFG_POLICER_CIR_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_QUEUE_CFG_POLICER_CIR_SET(v)		(((v) & MV_DP_MSG_QUEUE_CFG_POLICER_CIR_MASK) \
									<< MV_DP_MSG_QUEUE_CFG_POLICER_CIR_OFFS)
#define MV_DP_MSG_QUEUE_CFG_POLICER_CIR_GET(v)		(((v) >> MV_DP_MSG_QUEUE_CFG_POLICER_CIR_OFFS) \
									& MV_DP_MSG_QUEUE_CFG_POLICER_CIR_MASK)

#define MV_DP_MSG_QUEUE_CFG_POLICER_EIR_WORD2		(2)
#define MV_DP_MSG_QUEUE_CFG_POLICER_EIR_OFFS		(0)
#define MV_DP_MSG_QUEUE_CFG_POLICER_EIR_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_QUEUE_CFG_POLICER_EIR_SET(v)		(((v) & MV_DP_MSG_QUEUE_CFG_POLICER_EIR_MASK) \
									<< MV_DP_MSG_QUEUE_CFG_POLICER_EIR_OFFS)
#define MV_DP_MSG_QUEUE_CFG_POLICER_EIR_GET(v)		(((v) >> MV_DP_MSG_QUEUE_CFG_POLICER_EIR_OFFS) \
									& MV_DP_MSG_QUEUE_CFG_POLICER_EIR_MASK)

#define MV_DP_MSG_QUEUE_CFG_POLICER_CBS_WORD3		(3)
#define MV_DP_MSG_QUEUE_CFG_POLICER_CBS_OFFS		(0)
#define MV_DP_MSG_QUEUE_CFG_POLICER_CBS_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_QUEUE_CFG_POLICER_CBS_SET(v)		(((v) & MV_DP_MSG_QUEUE_CFG_POLICER_CBS_MASK) \
									<< MV_DP_MSG_QUEUE_CFG_POLICER_CBS_OFFS)
#define MV_DP_MSG_QUEUE_CFG_POLICER_CBS_GET(v)		(((v) >> MV_DP_MSG_QUEUE_CFG_POLICER_CBS_OFFS) \
									& MV_DP_MSG_QUEUE_CFG_POLICER_CBS_MASK)

#define MV_DP_MSG_QUEUE_CFG_POLICER_EBS_WORD4		(4)
#define MV_DP_MSG_QUEUE_CFG_POLICER_EBS_OFFS		(0)
#define MV_DP_MSG_QUEUE_CFG_POLICER_EBS_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_QUEUE_CFG_POLICER_EBS_SET(v)		(((v) & MV_DP_MSG_QUEUE_CFG_POLICER_EBS_MASK) \
									<< MV_DP_MSG_QUEUE_CFG_POLICER_EBS_OFFS)
#define MV_DP_MSG_QUEUE_CFG_POLICER_EBS_GET(v)		(((v) >> MV_DP_MSG_QUEUE_CFG_POLICER_EBS_OFFS) \
									& MV_DP_MSG_QUEUE_CFG_POLICER_EBS_MASK)

#define MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_WORD5            (5)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_OFFS             (0)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_MASK             (0x000000FF)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_SET(v)		(((v) & MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_MASK) \
									<< MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_OFFS)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_GET(v)		(((v) >> MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_OFFS) \
									& MV_DP_MSG_QUEUE_CFG_QUEUE_PRIO_MASK)

#define MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_WORD5          (5)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_OFFS           (16)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_MASK           (0x0000FFFF)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_SET(v)		(((v) & MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_MASK) \
									<< MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_OFFS)
#define MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_GET(v)		(((v) >> MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_OFFS) \
									& MV_DP_MSG_QUEUE_CFG_QUEUE_WEIGHT_MASK)

/************ QUEUE CFG MSG END***************************/


/************INGRESS PRIO CFG MSG START***************************/

/*
*INGRESS_PRIO_CFG_SET request   -- ALL INGRESS_PRIO_CFG Fields
*INGRESS_PRIO_CFG_SET reply     -- NONE
*
*INGRESS_PRIO_CFG_GET request   -- NONE
*INGRESS_PRIO_CFG_GET reply     -- ALL INGRESS_PRIO_CFG Fields
******/

#define MV_DP_MSG_INGRESS_PRIO_CFG_SET_TX_SIZE	(4 + MV_NSS_DP_PRIO_NUM)
#define MV_DP_MSG_INGRESS_PRIO_CFG_SET_RX_SIZE	(0)

#define MV_DP_MSG_INGRESS_PRIO_CFG_GET_TX_SIZE	(0)
#define MV_DP_MSG_INGRESS_PRIO_CFG_GET_RX_SIZE	(4 + MV_NSS_DP_PRIO_NUM)


/************INGRESS PRIO CFG Offsets**************************/


#define MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_WORD0	(0)
#define MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_OFF	(0)
#define MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_MASK	(0x000000FF)
#define MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_SET(v)	(((v) & MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_MASK) \
									<< MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_OFF)
#define MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_GET(v)	(((v) >> MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_OFF) \
									& MV_DP_MSG_INGRESS_PRIO_CFG_MNGMT_MASK)

#define MV_DP_MSG_INGRESS_PRIO_CFG_RFU1_WORD0	(0)
#define MV_DP_MSG_INGRESS_PRIO_CFG_RFU1_OFF	(8)
#define MV_DP_MSG_INGRESS_PRIO_CFG_RFU1_MASK	(0x00FFFFFF)

#define MV_DP_MSG_INGRESS_PRIO_CFG_MAP_WORD1	(1)
#define MV_DP_MSG_INGRESS_PRIO_CFG_MAP_OFFS_B	(0)	/* Offset in Bytes */
/*Size in bytes. Bytestream starting with PRI0_QUEUE, PRI1_QUEUE, etc. */
#define MV_DP_MSG_INGRESS_PRIO_CFG_MAP_SIZE	(MV_NSS_DP_PRIO_NUM)


/************INGRESS PRIO CFG END***************************/

/************INGRESS QOS POLICY MSG START***************************/

/*
*INGRESS_QOS_POLICY_SET request   -- ALL INGRESS_QOS_POLICY Fields, except RFU2
*INGRESS_QOS_POLICY_SET reply     -- NONE
*
*INGRESS_QOS_POLICY_GET request   -- POLICY_ID, RFU2
*INGRESS_QOS_POLICY_GET reply     -- ALL INGRESS_QOS_POLICY Fields, except RFU2
******/

#define MV_DP_MSG_INGRESS_QOS_POLICY_SET_TX_SIZE	(80)
#define MV_DP_MSG_INGRESS_QOS_POLICY_SET_RX_SIZE	(0)

#define MV_DP_MSG_INGRESS_QOS_POLICY_GET_TX_SIZE	(4)
#define MV_DP_MSG_INGRESS_QOS_POLICY_GET_RX_SIZE	(80)


/************INGRESS QOS POLICY Offsets**************************/
#define MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_WORD1		(1)
#define MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_OFFS		(0)
#define MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_MASK		(0x000000FF)
#define MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_SET(v)	(((v) & MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_MASK) \
									<< MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_OFFS)
#define MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_GET(v)	(((v) >> MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_OFFS) \
									& MV_DP_MSG_INGRESS_QOS_POLICY_TYPE_MASK)

#define MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_WORD1	(1)
#define MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_OFFS	(8)
#define MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_MASK	(0x000000FF)
#define MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_SET(v)	(((v) & MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_MASK) \
									<< MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_OFFS)
#define MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_GET(v)	(((v) >> MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_OFFS) \
									& MV_DP_MSG_INGRESS_QOS_POLICY_PRIO_DEF_MASK)

#define MV_DP_MSG_INGRESS_QOS_POLICY_RFU2_WORD1		(1)
#define MV_DP_MSG_INGRESS_QOS_POLICY_RFU2_OFFS		(16)
#define MV_DP_MSG_INGRESS_QOS_POLICY_RFU2_MASK		(0x0000FFFF)


#define MV_DP_MSG_INGRESS_QOS_POLICY_L2TOPRIO_WORD2	(2)
#define MV_DP_MSG_INGRESS_QOS_POLICY_L2TOPRIO_OFFS_B	(0)	/* Offset in Bytes */
/*Size in bytes. Bytestream starting with L22PRIO[0],L22PRIO[1], etc. */
#define MV_DP_MSG_INGRESS_QOS_POLICY_L2TOPRIO_SIZE	(8)

#define MV_DP_MSG_INGRESS_QOS_POLICY_DSCPTOPRIO_WORD4	(4)
#define MV_DP_MSG_INGRESS_QOS_POLICY_DSCPTOPRIO_OFFS_B	(0)	/* Offset in Bytes */
/*Size in bytes. Bytestream starting with DSCP2PRIO[0], DSCP2PRIO[1], etc. */
#define MV_DP_MSG_INGRESS_QOS_POLICY_DSCPTOPRIO_SIZE	(64)

/************INGRESS QOS POLICY END*******************************/

/************EGRESS PRIO CFG MSG START***************************/

/*
*EGRESS_PRIO_CFG_SET request   -- ALL EGRESS_PRIO_CFG Fields
*EGRESS_PRIO_CFG_SET reply     -- NONE
*
*EGRESS_PRIO_CFG_GET request   -- NONE
*EGRESS_PRIO_CFG_GET reply     -- ALL EGRESS_PRIO_CFG Fields
******/

#define MV_DP_MSG_EGRESS_PRIO_CFG_SET_TX_SIZE	(MV_NSS_DP_PRIO_NUM)
#define MV_DP_MSG_EGRESS_PRIO_CFG_SET_RX_SIZE	(0)

#define MV_DP_MSG_EGRESS_PRIO_CFG_GET_TX_SIZE	(0)
#define MV_DP_MSG_EGRESS_PRIO_CFG_GET_RX_SIZE	(MV_NSS_DP_PRIO_NUM)


/************EGRESS PRIO CFG Offsets**************************/

#define MV_DP_MSG_EGRESS_PRIO_CFG_MAP_WORD0	(0)
#define MV_DP_MSG_EGRESS_PRIO_CFG_MAP_OFFS_B	(0)	/*Offset in Bytes*/
/*Size in bytes. Bytestream starting with PRI0_QUEUE, PRI1_QUEUE, etc. */
#define MV_DP_MSG_EGRESS_PRIO_CFG_MAP_SIZE	(MV_NSS_DP_PRIO_NUM)


/************EGRESS PRIO CFG END***************************/



/************EGRESS QOS POLICY MSG START***************************/

/*
*EGRESS_QOS_POLICY_SET request   -- ALL EGRESS_QOS_POLICY Fields
*EGRESS_QOS_POLICY_SET reply     -- NONE
*
*EGRESS_QOS_POLICY_GET request   -- POLICY_ID, RFU1
*EGRESS_QOS_POLICY_GET reply     -- ALL EGRESS_QOS_POLICY Fields
******/
#define MV_DP_MSG_EGRESS_QOS_POLICY_SET_TX_SIZE		(52)
#define MV_DP_MSG_EGRESS_QOS_POLICY_SET_RX_SIZE		(0)

#define MV_DP_MSG_EGRESS_QOS_POLICY_GET_TX_SIZE		(4)
#define MV_DP_MSG_EGRESS_QOS_POLICY_GET_RX_SIZE		(52)


/************EGRESS QOS POLICY Offsets**************************/
#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2UP_WORD1	(1)
#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2UP_OFFS_B	(0)	/*Offset in Bytes*/
/*Size in bytes. Bytestream starting with PRIO2UP[0], PRIO2UP[1], etc. */
#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2UP_SIZE	(16)

#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2DSCP_WORD5	(5)
#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2DSCP_OFFS_B	(0)	/*Offset in Bytes*/
/*Size in bytes. Bytestream starting with PRIO2DSCP[0], PRIO2DSCP[1], etc. */
#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2DSCP_SIZE	(16)

#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2PCP_WORD9	(9)
#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2PCP_OFFS_B	(0)	/*Offset in Bytes*/
/*Size in bytes. Bytestream starting with PRIO2PCP[0], PRIO2PCP[1], etc. */
#define MV_DP_MSG_EGRESS_QOS_POLICY_PRIO2PCP_SIZE	(16)


/************EGRESS QOS POLICY END***************************/


/************FLOW MSG START***************************/
/*
*FLOW_DELETE request		-- FLOW_ID
*FLOW_DELETE reply		-- NONE
*
*FLOW_DELETE_ALL request	-- NONE
*FLOW_DELETE_ALL reply		-- NONE
*
*FLOW_STATUS_SET request	-- FLOW_ID, FLOW_STATUS
*FLOW_STATUS_SET reply		-- NONE
*
*FLOW_STATUS_GET request	-- FLOW_ID
*FLOW_STATUS_GET reply		-- FLOW_STATUS
*
*FLOW_STATS_RESET request	-- FLOW_ID
*FLOW_STATS_RESET reply		-- NONE
*
*FLOW_STATS_GET request		-- FLOW_ID
*FLOW_STATS_GET reply		-- FLOW_STATS fields
*
*FLOW_STATS_GET_BULK request	-- FLOW_ID
*FLOW_STATS_GET_BULK reply	-- FLOW_STATS fields
*
*FLOW_COUNT_GET request		-- NONE
*FLOW_COUNT_GET reply		-- FLOW_COUNT
*
*FLOW_SET request		-- ALL FLOW PARAMS
*FLOW_SET reply			-- ALL FLOW PARAMS with ID set by FW
*
*FLOW_GET request		-- FLOW_ID
*FLOW_GET reply			-- ALL FLOW PARAMS
*
*
******/

#define MV_DP_MSG_FLOW_DELETE_TX_SIZE		(4)
#define MV_DP_MSG_FLOW_DELETE_RX_SIZE		(0)

#define MV_DP_MSG_FLOW_DELETE_ALL_TX_SIZE	(0)
#define MV_DP_MSG_FLOW_DELETE_ALL_RX_SIZE	(0)

#define MV_DP_MSG_FLOW_STATUS_SET_TX_SIZE	(8) /*flow_id+status*/
#define MV_DP_MSG_FLOW_STATUS_SET_RX_SIZE	(0)

#define MV_DP_MSG_FLOW_STATUS_GET_TX_SIZE	(4) /*flow_id*/
#define MV_DP_MSG_FLOW_STATUS_GET_RX_SIZE	(8) /*flow id + status*/

#define MV_DP_MSG_FLOW_STATS_RESET_TX_SIZE	(4)
#define MV_DP_MSG_FLOW_STATS_RESET_RX_SIZE	(0)

#define MV_DP_MSG_FLOW_STATS_GET_TX_SIZE	(4)
#define MV_DP_MSG_FLOW_STATS_GET_RX_SIZE	(24)

#define MV_DP_MSG_FLOW_STATS_GET_BULK_TX_SIZE	(8)
#define MV_DP_MSG_FLOW_STATS_GET_BULK_RX_SIZE	(24)

#define MV_DP_MSG_FLOW_COUNT_GET_TX_SIZE	(0)
#define MV_DP_MSG_FLOW_COUNT_GET_RX_SIZE	(4)

#define MV_DP_MSG_FLOW_SET_TX_SIZE		(43*4)
#define MV_DP_MSG_FLOW_SET_RX_SIZE		(43*4)

#define MV_DP_MSG_FLOW_GET_TX_SIZE		(4)
#define MV_DP_MSG_FLOW_GET_RX_SIZE		(43*4)

/************FLOW Offsets**************************/
/* ALL FLOW APIs except for get count and delete ALL*/
#define MV_DP_MSG_FLOW_ID_WORD0			(0)
#define MV_DP_MSG_FLOW_ID_OFFS			(0)
#define MV_DP_MSG_FLOW_ID_MASK			(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_ID_SET(v)		(((v) & MV_DP_MSG_FLOW_ID_MASK) << MV_DP_MSG_FLOW_ID_OFFS)
#define MV_DP_MSG_FLOW_ID_GET(v)		(((v) >> MV_DP_MSG_FLOW_ID_OFFS) & MV_DP_MSG_FLOW_ID_MASK)

/* ALL Get/Set Status and Flow API*/
#define MV_DP_MSG_FLOW_STATUS_WORD1		(1)
#define MV_DP_MSG_FLOW_STATUS_OFFS		(0)
#define MV_DP_MSG_FLOW_STATUS_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_STATUS_SET(v)		(((v) & MV_DP_MSG_FLOW_STATUS_MASK) << MV_DP_MSG_FLOW_STATUS_OFFS)
#define MV_DP_MSG_FLOW_STATUS_GET(v)		(((v) >> MV_DP_MSG_FLOW_STATUS_OFFS) & MV_DP_MSG_FLOW_STATUS_MASK)

/*Flow get/set only */
#define MV_DP_MSG_FLOW_IDLE_WORD2		(2)
#define MV_DP_MSG_FLOW_IDLE_OFFS		(0)
#define MV_DP_MSG_FLOW_IDLE_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_IDLE_SET(v)		(((v) & MV_DP_MSG_FLOW_IDLE_MASK) << MV_DP_MSG_FLOW_IDLE_OFFS)
#define MV_DP_MSG_FLOW_IDLE_GET(v)		(((v) >> MV_DP_MSG_FLOW_IDLE_OFFS) & MV_DP_MSG_FLOW_IDLE_MASK)

/* FLOW_COUNT Reply */
#define MV_DP_MSG_FLOW_COUNT_WORD0		(0)
#define MV_DP_MSG_FLOW_COUNT_OFFS		(0)
#define MV_DP_MSG_FLOW_COUNT_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_COUNT_SET(v)		(((v) & MV_DP_MSG_FLOW_COUNT_MASK) << MV_DP_MSG_FLOW_COUNT_OFFS)
#define MV_DP_MSG_FLOW_COUNT_GET(v)		(((v) >> MV_DP_MSG_FLOW_COUNT_OFFS) & MV_DP_MSG_FLOW_COUNT_MASK)

/* FLOW_STATS BULK REQUEST, after flow ID at [0]*/
#define MV_DP_MSG_FLOW_OPTIONS_WORD1		(1)
#define MV_DP_MSG_FLOW_OPTIONS_OFFS		(0)
#define MV_DP_MSG_FLOW_OPTIONS_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_OPTIONS_SET(v)		(((v) & MV_DP_MSG_FLOW_OPTIONS_MASK) << MV_DP_MSG_FLOW_OPTIONS_OFFS)
#define MV_DP_MSG_FLOW_OPTIONS_GET(v)		(((v) >> MV_DP_MSG_FLOW_OPTIONS_OFFS) & MV_DP_MSG_FLOW_OPTIONS_MASK)

/* FLOW_STATS REPLY*/
#define MV_DP_MSG_FLOW_STATS_LAST_TS_WORD1	(1)
#define MV_DP_MSG_FLOW_STATS_LAST_TS_OFFS	(0)
#define MV_DP_MSG_FLOW_STATS_LAST_TS_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_STATS_LAST_TS_SET(v)	(((v) & MV_DP_MSG_FLOW_STATS_LAST_TS_MASK) \
										<< MV_DP_MSG_FLOW_STATS_LAST_TS_OFFS)
#define MV_DP_MSG_FLOW_STATS_LAST_TS_GET(v)	(((v) >> MV_DP_MSG_FLOW_STATS_LAST_TS_OFFS) \
										& MV_DP_MSG_FLOW_STATS_LAST_TS_MASK)

#define MV_DP_MSG_FLOW_STATS_RX_PKTS_WORD2	(2)
#define MV_DP_MSG_FLOW_STATS_RX_PKTS_OFFS_B	(0)
#define MV_DP_MSG_FLOW_STATS_RX_PKTS_SIZE	(8)


#define MV_DP_MSG_FLOW_STATS_RX_OCTS_WORD4	(4)
#define MV_DP_MSG_FLOW_STATS_RX_OCTS_OFFS_B	(0)
#define MV_DP_MSG_FLOW_STATS_RX_OCTS_SIZE	(8)


/* FLOW_SET/FLOW_GET */
/*FLOW_ID and STATUS at words 0 - 1 as above
CLS and ACT are the same at different offsets */
/******************CLS*******************************************/
#define MV_DP_MSG_FLOW_CLS_BASE_WORD3		(3)
#define MV_DP_MSG_FLOW_ACT_BASE_WORD23		(23)

#define MV_DP_MSG_FLOW_PRESENT_WORD0		(0)
#define MV_DP_MSG_FLOW_PRESENT_OFFS		(0)
#define MV_DP_MSG_FLOW_PRESENT_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_PRESENT_SET(v)		(((v) & MV_DP_MSG_FLOW_PRESENT_MASK) << MV_DP_MSG_FLOW_PRESENT_OFFS)
#define MV_DP_MSG_FLOW_PRESENT_GET(v)		(((v) >> MV_DP_MSG_FLOW_PRESENT_OFFS) & MV_DP_MSG_FLOW_PRESENT_MASK)

#define MV_DP_MSG_FLOW_FLBL_WORD1		(1)
#define MV_DP_MSG_FLOW_FLBL_OFFS		(0)
#define MV_DP_MSG_FLOW_FLBL_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_FLBL_SET(v)		(((v) & MV_DP_MSG_FLOW_FLBL_MASK) << MV_DP_MSG_FLOW_FLBL_OFFS)
#define MV_DP_MSG_FLOW_FLBL_GET(v)		(((v) >> MV_DP_MSG_FLOW_FLBL_OFFS) & MV_DP_MSG_FLOW_FLBL_MASK)


#define MV_DP_MSG_FLOW_OPAQUE_WORD2		(2)
#define MV_DP_MSG_FLOW_OPAQUE_OFFS		(0)
#define MV_DP_MSG_FLOW_OPAQUE_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_FLOW_OPAQUE_SET(v)		(((v) & MV_DP_MSG_FLOW_OPAQUE_MASK) << MV_DP_MSG_FLOW_OPAQUE_OFFS)
#define MV_DP_MSG_FLOW_OPAQUE_GET(v)		(((v) >> MV_DP_MSG_FLOW_OPAQUE_OFFS) & MV_DP_MSG_FLOW_OPAQUE_MASK)

#define MV_DP_MSG_FLOW_ETH_TYPE_WORD3		(3)
#define MV_DP_MSG_FLOW_ETH_TYPE_OFFS		(0)
#define MV_DP_MSG_FLOW_ETH_TYPE_MASK		(0xFFFF)
#define MV_DP_MSG_FLOW_ETH_TYPE_SET(v)		(((v) & MV_DP_MSG_FLOW_ETH_TYPE_MASK) << MV_DP_MSG_FLOW_ETH_TYPE_OFFS)
#define MV_DP_MSG_FLOW_ETH_TYPE_GET(v)		(((v) >> MV_DP_MSG_FLOW_ETH_TYPE_OFFS) & MV_DP_MSG_FLOW_ETH_TYPE_MASK)


#define MV_DP_MSG_FLOW_PORT_DST_WORD3		(3)
#define MV_DP_MSG_FLOW_PORT_DST_OFFS		(16)
#define MV_DP_MSG_FLOW_PORT_DST_MASK		(0xFF)
#define MV_DP_MSG_FLOW_PORT_DST_SET(v)		(((v) & MV_DP_MSG_FLOW_PORT_DST_MASK) << MV_DP_MSG_FLOW_PORT_DST_OFFS)
#define MV_DP_MSG_FLOW_PORT_DST_GET(v)		(((v) >> MV_DP_MSG_FLOW_PORT_DST_OFFS) & MV_DP_MSG_FLOW_PORT_DST_MASK)


#define MV_DP_MSG_FLOW_PORT_SRC_WORD3		(3)
#define MV_DP_MSG_FLOW_PORT_SRC_OFFS		(24)
#define MV_DP_MSG_FLOW_PORT_SRC_MASK		(0xFF)
#define MV_DP_MSG_FLOW_PORT_SRC_SET(v)		(((v) & MV_DP_MSG_FLOW_PORT_SRC_MASK) << MV_DP_MSG_FLOW_PORT_SRC_OFFS)
#define MV_DP_MSG_FLOW_PORT_SRC_GET(v)		(((v) >> MV_DP_MSG_FLOW_PORT_SRC_OFFS) & MV_DP_MSG_FLOW_PORT_SRC_MASK)


#define MV_DP_MSG_FLOW_LLC_SSAP_WORD4		(4)
#define MV_DP_MSG_FLOW_LLC_SSAP_OFFS		(0)
#define MV_DP_MSG_FLOW_LLC_SSAP_MASK		(0xFFFF)
#define MV_DP_MSG_FLOW_LLC_SSAP_SET(v)		(((v) & MV_DP_MSG_FLOW_LLC_SSAP_MASK) << MV_DP_MSG_FLOW_LLC_SSAP_OFFS)
#define MV_DP_MSG_FLOW_LLC_SSAP_GET(v)		(((v) >> MV_DP_MSG_FLOW_LLC_SSAP_OFFS) & MV_DP_MSG_FLOW_LLC_SSAP_MASK)


#define MV_DP_MSG_FLOW_LLC_DSAP_WORD4		(4)
#define MV_DP_MSG_FLOW_LLC_DSAP_OFFS		(16)
#define MV_DP_MSG_FLOW_LLC_DSAP_MASK		(0xFFFF)
#define MV_DP_MSG_FLOW_LLC_DSAP_SET(v)		(((v) & MV_DP_MSG_FLOW_LLC_DSAP_MASK) << MV_DP_MSG_FLOW_LLC_DSAP_OFFS)
#define MV_DP_MSG_FLOW_LLC_DSAP_GET(v)		(((v) >> MV_DP_MSG_FLOW_LLC_DSAP_OFFS) & MV_DP_MSG_FLOW_LLC_DSAP_MASK)


#define MV_DP_MSG_FLOW_L4_DST_WORD5		(5)
#define MV_DP_MSG_FLOW_L4_DST_OFFS		(0)
#define MV_DP_MSG_FLOW_L4_DST_MASK		(0xFFFF)
#define MV_DP_MSG_FLOW_L4_DST_SET(v)		(((v) & MV_DP_MSG_FLOW_L4_DST_MASK) << MV_DP_MSG_FLOW_L4_DST_OFFS)
#define MV_DP_MSG_FLOW_L4_DST_GET(v)		(((v) >> MV_DP_MSG_FLOW_L4_DST_OFFS) & MV_DP_MSG_FLOW_L4_DST_MASK)


#define MV_DP_MSG_FLOW_L4_SRC_WORD5		(5)
#define MV_DP_MSG_FLOW_L4_SRC_OFFS		(16)
#define MV_DP_MSG_FLOW_L4_SRC_MASK		(0xFFFF)
#define MV_DP_MSG_FLOW_L4_SRC_SET(v)		(((v) & MV_DP_MSG_FLOW_L4_SRC_MASK) << MV_DP_MSG_FLOW_L4_SRC_OFFS)
#define MV_DP_MSG_FLOW_L4_SRC_GET(v)		(((v) >> MV_DP_MSG_FLOW_L4_SRC_OFFS) & MV_DP_MSG_FLOW_L4_SRC_MASK)


#define MV_DP_MSG_FLOW_PRIO_VAL_WORD6		(6)
#define MV_DP_MSG_FLOW_PRIO_VAL_OFFS		(0)
#define MV_DP_MSG_FLOW_PRIO_VAL_MASK		(0xFF)
#define MV_DP_MSG_FLOW_PRIO_VAL_SET(v)		(((v) & MV_DP_MSG_FLOW_PRIO_VAL_MASK) << MV_DP_MSG_FLOW_PRIO_VAL_OFFS)
#define MV_DP_MSG_FLOW_PRIO_VAL_GET(v)		(((v) >> MV_DP_MSG_FLOW_PRIO_VAL_OFFS) & MV_DP_MSG_FLOW_PRIO_VAL_MASK)

#define MV_DP_MSG_FLOW_PRIO_ACT_WORD6		(6)
#define MV_DP_MSG_FLOW_PRIO_ACT_OFFS		(8)
#define MV_DP_MSG_FLOW_PRIO_ACT_MASK		(0xFF)
#define MV_DP_MSG_FLOW_PRIO_ACT_SET(v)		(((v) & MV_DP_MSG_FLOW_PRIO_ACT_MASK) << MV_DP_MSG_FLOW_PRIO_ACT_OFFS)
#define MV_DP_MSG_FLOW_PRIO_ACT_GET(v)		(((v) >> MV_DP_MSG_FLOW_PRIO_ACT_OFFS) & MV_DP_MSG_FLOW_PRIO_ACT_MASK)


#define MV_DP_MSG_FLOW_L4_PROTO_WORD6		(6)
#define MV_DP_MSG_FLOW_L4_PROTO_OFFS		(16)
#define MV_DP_MSG_FLOW_L4_PROTO_MASK		(0xFF)
#define MV_DP_MSG_FLOW_L4_PROTO_SET(v)		(((v) & MV_DP_MSG_FLOW_L4_PROTO_MASK) << MV_DP_MSG_FLOW_L4_PROTO_OFFS)
#define MV_DP_MSG_FLOW_L4_PROTO_GET(v)		(((v) >> MV_DP_MSG_FLOW_L4_PROTO_OFFS) & MV_DP_MSG_FLOW_L4_PROTO_MASK)

#define MV_DP_MSG_FLOW_IPVER_WORD6		(6)
#define MV_DP_MSG_FLOW_IPVER_OFFS		(24)
#define MV_DP_MSG_FLOW_IPVER_MASK		(0xFF)
#define MV_DP_MSG_FLOW_IPVER_SET(v)		(((v) & MV_DP_MSG_FLOW_IPVER_MASK) << MV_DP_MSG_FLOW_IPVER_OFFS)
#define MV_DP_MSG_FLOW_IPVER_GET(v)		(((v) >> MV_DP_MSG_FLOW_IPVER_OFFS) & MV_DP_MSG_FLOW_IPVER_MASK)

#define MV_DP_MSG_FLOW_SNAP_WORD7		(7)
#define MV_DP_MSG_FLOW_SNAP_OFFS_B		(0)
#define MV_DP_MSG_FLOW_SNAP_SIZE		(5) /* size in bytes */

#define MV_DP_MSG_FLOW_RFU1_WORD8		(8)
#define MV_DP_MSG_FLOW_RFU1_OFFS		(8)
#define MV_DP_MSG_FLOW_RFU1_MASK		(0xFFFFFF)
#define MV_DP_MSG_FLOW_RFU1_SET(v)		(((v) & MV_DP_MSG_FLOW_RFU1_MASK) << MV_DP_MSG_FLOW_RFU1_OFFS)
#define MV_DP_MSG_FLOW_RFU1_GET(v)		(((v) >> MV_DP_MSG_FLOW_RFU1_OFFS) & MV_DP_MSG_FLOW_RFU1_MASK)


#define MV_DP_MSG_FLOW_IP_DST_WORD9		(9)
#define MV_DP_MSG_FLOW_IP_DST_OFFS_B		(0)
#define MV_DP_MSG_FLOW_IP_DST_SIZE		(16) /* size in bytes */

#define MV_DP_MSG_FLOW_IP_SRC_WORD13		(13)
#define MV_DP_MSG_FLOW_IP_SRC_OFFS_B		(0)
#define MV_DP_MSG_FLOW_IP_SRC_SIZE		(16) /* size in bytes */

#define MV_DP_MSG_FLOW_L2_DST_WORD17		(17)
#define MV_DP_MSG_FLOW_L2_DST_OFFS_B		(0)
#define MV_DP_MSG_FLOW_L2_SIZE			(6) /* size in bytes */

#define MV_DP_MSG_FLOW_L2_SRC_WORD18		(18)
#define MV_DP_MSG_FLOW_L2_SRC_OFFS_B		(2)


/************FLOW END***************************/


/************DTLS MSG START***************************/

/*
*DTLS_SET request	-- ALL DTLS_SET Fields. Contains variable length parameters.
*				MUST be in buffer.
*DTLS_SET reply		-- NONE
*
*DTLS_GET request	-- DTLS_ID.
*DTLS_GET reply		-- ALL DTLS_SET Fields. Contains variable length parameters.
*				MUST be in buffer.
*
*DTLS_DELETE request	-- DTLS_ID
*DTLS_DELETE reply	-- None
*
*/

#define MV_DP_MSG_DTLS_SET_TX_SIZE		(54*4)
#define MV_DP_MSG_DTLS_SET_RX_SIZE		(0)

#define MV_DP_MSG_DTLS_GET_TX_SIZE		(4)
#define MV_DP_MSG_DTLS_GET_RX_SIZE		(54*4)

#define MV_DP_MSG_DTLS_DELETE_TX_SIZE		(4)
#define MV_DP_MSG_DTLS_DELETE_RX_SIZE		(0)

/************DTLS Offsets**************************/

#define MV_DP_MSG_DTLS_DTLS_ID_WORD0		(0)
#define MV_DP_MSG_DTLS_DTLS_ID_OFFS		(0)
#define MV_DP_MSG_DTLS_DTLS_ID_MASK		(0x0000FFFF)
#define MV_DP_MSG_DTLS_DTLS_ID_SET(v)		(((v) & MV_DP_MSG_DTLS_DTLS_ID_MASK) \
								<< MV_DP_MSG_DTLS_DTLS_ID_OFFS)
#define MV_DP_MSG_DTLS_DTLS_ID_GET(v)		(((v) >> MV_DP_MSG_DTLS_DTLS_ID_OFFS) \
								& MV_DP_MSG_DTLS_DTLS_ID_MASK)

#define MV_DP_MSG_DTLS_RFU1_WORD0		(0)
#define MV_DP_MSG_DTLS_RFU1_OFFS		(16)
#define MV_DP_MSG_DTLS_RFU1_MASK		(0x0000FFFF)


/* DTLS_SET/DTLS_GET */
#define MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_WORD1	(1)
#define MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_OFFS	(0)
#define MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_MASK	(0xFFFF)
#define MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_SET(v)	(((v) & MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_MASK) \
								<< MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_OFFS)
#define MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_GET(v)	(((v) >> MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_OFFS) \
								& MV_DP_MSG_DTLS_READ_MAC_SEC_LEN_MASK)

#define MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_WORD1	(1)
#define MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_OFFS	(16)
#define MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_MASK	(0xFFFF)
#define MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_SET(v)	(((v) & MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_MASK) \
								<< MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_OFFS)
#define MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_GET(v)	(((v) >> MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_OFFS) \
								& MV_DP_MSG_DTLS_WRITE_MAC_SEC_LEN_MASK)


#define MV_DP_MSG_DTLS_SEQ_ID_WORD2		(2)
#define MV_DP_MSG_DTLS_SEQ_ID_OFFS		(0)
#define MV_DP_MSG_DTLS_SEQ_ID_SIZE		(6)	/* size in bytes */

#define MV_DP_MSG_DTLS_RFU1_WORD3		(3)
#define MV_DP_MSG_DTLS_RFU1_OFFS		(16)	/* See MV_DP_MSG_CLIENT_RFU1_WORD1 */
#define MV_DP_MSG_DTLS_RFU1_MASK		(0x0000FFFF)

#define MV_DP_MSG_DTLS_EPOCH_WORD4		(4)
#define MV_DP_MSG_DTLS_EPOCH_OFFS		(0)
#define MV_DP_MSG_DTLS_EPOCH_MASK		(0x0000FFFF)
#define MV_DP_MSG_DTLS_EPOCH_SET(v)		(((v) & MV_DP_MSG_DTLS_EPOCH_MASK) \
								<< MV_DP_MSG_DTLS_EPOCH_OFFS)
#define MV_DP_MSG_DTLS_EPOCH_GET(v)		(((v) >> MV_DP_MSG_DTLS_EPOCH_OFFS) \
								& MV_DP_MSG_DTLS_EPOCH_MASK)

#define MV_DP_MSG_DTLS_VER_WORD4		(4)
#define MV_DP_MSG_DTLS_VER_OFFS			(16)
#define MV_DP_MSG_DTLS_VER_MASK			(0x000000FF)
#define MV_DP_MSG_DTLS_VER_SET(v)		(((v) & MV_DP_MSG_DTLS_VER_MASK) \
								<< MV_DP_MSG_DTLS_VER_OFFS)
#define MV_DP_MSG_DTLS_VER_GET(v)		(((v) >> MV_DP_MSG_DTLS_VER_OFFS) \
								& MV_DP_MSG_DTLS_VER_MASK)


#define MV_DP_MSG_DTLS_RFU2_WORD4		(4)
#define MV_DP_MSG_DTLS_RFU2_OFFS		(24)
#define MV_DP_MSG_DTLS_RFU2_MASK		(0x000000FF)



#define MV_DP_MSG_DTLS_MODE_WORD5		(5)
#define MV_DP_MSG_DTLS_MODE_OFFS		(0)
#define MV_DP_MSG_DTLS_MODE_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_DTLS_MODE_SET(v)		(((v) & MV_DP_MSG_DTLS_MODE_MASK) \
								<< MV_DP_MSG_DTLS_MODE_OFFS)
#define MV_DP_MSG_DTLS_MODE_GET(v)		(((v) >> MV_DP_MSG_DTLS_MODE_OFFS) \
								& MV_DP_MSG_DTLS_MODE_MASK)

#define MV_DP_MSG_DTLS_READ_MAC_SEC_WORD6	(6)
#define MV_DP_MSG_DTLS_READ_MAC_SEC_OFFS	(0)
#define MV_DP_MSG_DTLS_READ_MAC_SEC_SIZE	(64) /*max size in bytes as in READ_SEC_LEN*/

#define MV_DP_MSG_DTLS_WRITE_MAC_SEC_WORD22	(22)
#define MV_DP_MSG_DTLS_WRITE_MAC_SEC_OFFS	(0)
#define MV_DP_MSG_DTLS_WRITE_MAC_SEC_SIZE	(64) /*max size in bytes as in WRITE_SEC_LEN*/

#define MV_DP_MSG_DTLS_READ_KEY_WORD38		(38)
#define MV_DP_MSG_DTLS_READ_KEY_OFFS		(0)
#define MV_DP_MSG_DTLS_READ_KEY_SIZE		(32) /*max size in bytes as in WRITE_SEC_LEN*/

#define MV_DP_MSG_DTLS_WRITE_KEY_WORD46		(46)
#define MV_DP_MSG_DTLS_WRITE_KEY_OFFS		(0)
#define MV_DP_MSG_DTLS_WRITE_KEY_SIZE		(32) /*max size in bytes as in WRITE_SEC_LEN*/

/*last message			word		(54) */


/************DTLS END***************************/

/************SYS_DIMENSION MSG START***************************/

/*
*SYS_DIMENSION_GET request	-- ENTIY_TYPE.
*SYS_DIMENSION_GET reply	-- ALL SYS_DIMENSIONS Fields.
*
*/
#define MV_DP_MSG_SYS_DIMENSION_GET_TX_SIZE		(4)
#define MV_DP_MSG_SYS_DIMENSION_GET_RX_SIZE		(8)


/************SYS_DIMENSION Offsets**************************/

#define MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_WORD0		(0)
#define MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_OFFS		(0)
#define MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_MASK		(0x000000FF)
#define MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_SET(v)			(((v) & MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_MASK) \
								<< MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_OFFS)
#define MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_GET(v)			(((v) >> MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_OFFS) \
								& MV_DP_MSG_SYS_DIMENSION_ENT_TYPE_MASK)

#define MV_DP_MSG_SYS_DIMENSION_RFU1_WORD0		(0)
#define MV_DP_MSG_SYS_DIMENSION_RFU1_OFFS		(8)
#define MV_DP_MSG_SYS_DIMENSION_RFU1_MASK		(0xFFFFFF)


#define MV_DP_MSG_SYS_DIMENSION_NUM_WORD1		(1)
#define MV_DP_MSG_SYS_DIMENSION_NUM_OFFS		(0)
#define MV_DP_MSG_SYS_DIMENSION_NUM_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_SYS_DIMENSION_NUM_SET(v)		(((v) & MV_DP_MSG_SYS_DIMENSION_NUM_MASK) \
								<< MV_DP_MSG_SYS_DIMENSION_NUM_OFFS)
#define MV_DP_MSG_SYS_DIMENSION_NUM_GET(v)		(((v) >> MV_DP_MSG_SYS_DIMENSION_NUM_OFFS) \
								& MV_DP_MSG_SYS_DIMENSION_NUM_MASK)


/************SYS_DIMENSION END***************************/


/************HASH PROFILE MSG START***************************/
/*
*HASH_PROF_SET request      -- ALL HASH_PROF_SET Fields.
*
*HASH_PROF_SET reply        -- NONE
*
*HASH_PROF_DELETE request   -- PROFILE_ID.
*HASH_PROF_DELETE reply	    -- NONE
*
*/
#define MV_DP_MSG_HASH_PROF_SET_TX_SIZE		(28)
#define MV_DP_MSG_HASH_PROF_SET_RX_SIZE		(0)

#define MV_DP_MSG_HASH_PROF_DEL_TX_SIZE		(4)
#define MV_DP_MSG_HASH_PROF_DEL_RX_SIZE		(0)

#define MV_DP_MSG_HASH_PROF_GET_TX_SIZE		(4)
#define MV_DP_MSG_HASH_PROF_GET_RX_SIZE		(28)

/************HASH PROFILE Offsets**************************/

#define MV_DP_MSG_HASH_PROF_PROF_ID_WORD0	(0)
#define MV_DP_MSG_HASH_PROF_PROF_ID_OFFS	(0)
#define MV_DP_MSG_HASH_PROF_PROF_ID_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_HASH_PROF_PROF_ID_SET(v)	(((v) & MV_DP_MSG_HASH_PROF_PROF_ID_MASK) \
							<< MV_DP_MSG_HASH_PROF_PROF_ID_OFFS)
#define MV_DP_MSG_HASH_PROF_PROF_ID_GET(v)	(((v) >> MV_DP_MSG_HASH_PROF_PROF_ID_OFFS) \
							& MV_DP_MSG_HASH_PROF_PROF_ID_MASK)

#define MV_DP_MSG_HASH_PROF_TCP_UDP_BM_WORD1	(1)
#define MV_DP_MSG_HASH_PROF_TCP_UDP_BM_OFFS	(0)
#define MV_DP_MSG_HASH_PROF_TCP_UDP_BM_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_HASH_PROF_TCP_UDP_BM_SET(v)	(((v) & MV_DP_MSG_HASH_PROF_TCP_UDP_BM_MASK) \
							<< MV_DP_MSG_HASH_PROF_TCP_UDP_BM_OFFS)
#define MV_DP_MSG_HASH_PROF_TCP_UDP_BM_GET(v)	(((v) >> MV_DP_MSG_HASH_PROF_TCP_UDP_BM_OFFS) \
							& MV_DP_MSG_HASH_PROF_TCP_UDP_BM_MASK)


#define MV_DP_MSG_HASH_PROF_IP_BM_WORD2		(2)
#define MV_DP_MSG_HASH_PROF_IP_BM_OFFS		(0)
#define MV_DP_MSG_HASH_PROF_IP_BM_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_HASH_PROF_IP_BM_GET(v)	(((v) & MV_DP_MSG_HASH_PROF_IP_BM_MASK) \
							<< MV_DP_MSG_HASH_PROF_IP_BM_OFFS)
#define MV_DP_MSG_HASH_PROF_IP_BM_SET(v)	(((v) >> MV_DP_MSG_HASH_PROF_IP_BM_OFFS) \
							& MV_DP_MSG_HASH_PROF_IP_BM_MASK)

#define MV_DP_MSG_HASH_PROF_NON_IP_BM_WORD3	(3)
#define MV_DP_MSG_HASH_PROF_NON_IP_BM_OFFS	(0)
#define MV_DP_MSG_HASH_PROF_NON_IP_BM_MASK	(0xFFFFFFFF)
#define MV_DP_MSG_HASH_PROF_NON_IP_BM_GET(v)	(((v) & MV_DP_MSG_HASH_PROF_NON_IP_BM_MASK) \
							<< MV_DP_MSG_HASH_PROF_NON_IP_BM_OFFS)
#define MV_DP_MSG_HASH_PROF_NON_IP_BM_SET(v)	(((v) >> MV_DP_MSG_HASH_PROF_NON_IP_BM_OFFS) \
							& MV_DP_MSG_HASH_PROF_NON_IP_BM_MASK)

#define MV_DP_MSG_HASH_PROF_RESULT_WORD		(4) /*word of index 0, currently 0..2*/
#define MV_DP_MSG_HASH_PROF_RESULT_OFFS		(0)
#define MV_DP_MSG_HASH_PROF_RESULT_MASK		(0xFFFFFFFF) /*Size in bytes */

#define MV_DP_MSG_HASH_PROF_RESULT_WORD_GET(v)	(MV_DP_MSG_HASH_PROF_RESULT_WORD + v)
#define MV_DP_MSG_HASH_PROF_RESULT_GET(v)	(((v) & MV_DP_MSG_HASH_PROF_RESULT_MASK) \
							<< MV_DP_MSG_HASH_PROF_RESULT_OFFS)
#define MV_DP_MSG_HASH_PROF_RESULT_SET(v)	(((v) >> MV_DP_MSG_HASH_PROF_RESULT_OFFS) \
							& MV_DP_MSG_HASH_PROF_RESULT_MASK)
/*TOTAL RESULTS IS 3 for now[0..2]*** result2 at word 6*/
/************HASH PROFILE MSG END*****************************/


/************MC CFG MSG START*********************************/
/*
*Request
*MC_BRIDGED_CFG_SET              -- ALL MC_BRIDGED_CFG Fields.
*MC_BRIDGED_CFG_GET              -- INDEX.
*MC_BRIDGED_CFG_DELETE           -- ALL MC_BRIDGED_CFG Fields.
*Reply
*MC_BRIDGED_CFG_SET              -- None
*MC_BRIDGED_CFG_GET              -- ALL MC_BRIDGED_CFG Fields.
*MC_BRIDGED_CFG_DELETE           -- None
*
*Request
*MC_TUNNELED_CFG_SET              -- ALL MC_TUNNELED_CFG Fields.
*MC_TUNNELED_CFG_GET              -- INDEX.
*MC_TUNNELED_CFG_DELETE           -- MGID.
*Reply
*MC_TUNNELED_CFG_SET              -- None
*MC_TUNNELED_CFG_GET              -- ALL MC_TUNNELED_CFG Fields.
*MC_TUNNELED_CFG_DELETE           -- None
*/

#define MV_DP_MSG_MC_BRIDGED_SET_TX_SIZE		(16)
#define MV_DP_MSG_MC_BRIDGED_SET_RX_SIZE		(0)

#define MV_DP_MSG_MC_BRIDGED_DEL_TX_SIZE		(16)
#define MV_DP_MSG_MC_BRIDGED_DEL_RX_SIZE		(0)

#define MV_DP_MSG_MC_BRIDGED_GET_TX_SIZE		(4)
#define MV_DP_MSG_MC_BRIDGED_GET_RX_SIZE		(16)

#define MV_DP_MSG_MC_TUNNELED_SET_TX_SIZE		(8)
#define MV_DP_MSG_MC_TUNNELED_SET_RX_SIZE		(0)

#define MV_DP_MSG_MC_TUNNELED_DEL_TX_SIZE		(4)
#define MV_DP_MSG_MC_TUNNELED_DEL_RX_SIZE		(0)

#define MV_DP_MSG_MC_TUNNELED_GET_TX_SIZE		(4)
#define MV_DP_MSG_MC_TUNNELED_GET_RX_SIZE		(8)


/************MC CFG Offsets**************************/

#define MV_DP_MSG_MC_BRIDGED_CFG_MAC_WORD0		(0)
#define MV_DP_MSG_MC_BRIDGED_CFG_MAC_OFFS_B		(0)
#define MV_DP_MSG_MC_BRIDGED_CFG_MAC_SIZE		(6) /*max size in bytes*/

#define MV_DP_MSG_MC_BRIDGED_CFG_VLAN_WORD2		(2)
#define MV_DP_MSG_MC_BRIDGED_CFG_VLAN_OFFS		(16)
#define MV_DP_MSG_MC_BRIDGED_CFG_VLAN_MASK		(0x0000FFFF)
#define MV_DP_MSG_MC_BRIDGED_CFG_VLAN_SET(v)		(((v) & MV_DP_MSG_MC_BRIDGED_CFG_VLAN_MASK) \
								<< MV_DP_MSG_MC_BRIDGED_CFG_VLAN_OFFS)
#define MV_DP_MSG_MC_BRIDGED_CFG_VLAN_GET(v)		(((v) >> MV_DP_MSG_MC_BRIDGED_CFG_VLAN_OFFS) \
								& MV_DP_MSG_MC_BRIDGED_CFG_VLAN_MASK)

#define MV_DP_MSG_MC_BRIDGED_CFG_OD_WORD3		(3)
#define MV_DP_MSG_MC_BRIDGED_CFG_OD_OFFS		(0)
#define MV_DP_MSG_MC_BRIDGED_CFG_OD_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_MC_BRIDGED_CFG_OD_SET(v)		(((v) & MV_DP_MSG_MC_BRIDGED_CFG_OD_MASK) \
								<< MV_DP_MSG_MC_BRIDGED_CFG_OD_OFFS)
#define MV_DP_MSG_MC_BRIDGED_CFG_OD_GET(v)		(((v) >> MV_DP_MSG_MC_BRIDGED_CFG_OD_OFFS) \
								& MV_DP_MSG_MC_BRIDGED_CFG_OD_MASK)

/*in Delete only MGID*/
#define MV_DP_MSG_MC_TUNNELED_CFG_MGID_WORD0		(0)
#define MV_DP_MSG_MC_TUNNELED_CFG_MGID_OFFS		(0)
#define MV_DP_MSG_MC_TUNNELED_CFG_MGID_MASK		(0x0000FFFF)
#define MV_DP_MSG_MC_TUNNELED_CFG_MGID_SET(v)		(((v) & MV_DP_MSG_MC_TUNNELED_CFG_MGID_MASK) \
								<< MV_DP_MSG_MC_TUNNELED_CFG_MGID_OFFS)
#define MV_DP_MSG_MC_TUNNELED_CFG_MGID_GET(v)		(((v) >> MV_DP_MSG_MC_TUNNELED_CFG_MGID_OFFS) \
								& MV_DP_MSG_MC_TUNNELED_CFG_MGID_MASK)

#define MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_WORD1		(1)
#define MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_OFFS		(0)
#define MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_MASK		(0x000000FF)
#define MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_SET(v)		(((v) & MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_MASK) \
								<< MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_OFFS)
#define MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_GET(v)		(((v) >> MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_OFFS) \
								& MV_DP_MSG_MC_TUNNELED_CFG_POL_ID_MASK)

/*get-delete only*/
#define MV_DP_MSG_MC_CFG_INDEX_WORD0			(0)
#define MV_DP_MSG_MC_CFG_INDEX_OFFS			(0)
#define MV_DP_MSG_MC_CFG_INDEX_MASK			(0x0000FFFF)
#define MV_DP_MSG_MC_CFG_INDEX_SET(v)			(((v) & MV_DP_MSG_MC_CFG_INDEX_MASK) \
										<< MV_DP_MSG_MC_CFG_INDEX_OFFS)
#define MV_DP_MSG_MC_CFG_INDEX_GET(v)			(((v) >> MV_DP_MSG_MC_CFG_INDEX_OFFS) \
										& MV_DP_MSG_MC_CFG_INDEX_MASK)

/************MC  MSG END********************************/


/************MIRROR MSG START***************************/
/*
*MIRROR_TUNNEL_SET request  -- ALL Fields.
*MIRROR_TUNNEL_SET reply    -- NONE
*
*MIRROR_TUNNEL_GET request  -- NONE
*MIRROR_TUNNEL_GET reply    -- ALL Fields
*
*MIRROR_CFG_SET request     -- ALL Fields.
*MIRROR_CFG_SET reply       -- NONE
*
*MIRROR_CFG_GET request     -- NONE
*MIRROR_CFG_GET reply       -- ALL Fields
*/

#define MV_DP_MSG_MIRROR_TUNNEL_SET_TX_SIZE		(48)
#define MV_DP_MSG_MIRROR_TUNNEL_SET_RX_SIZE		(0)

#define MV_DP_MSG_MIRROR_TUNNEL_GET_TX_SIZE		(4)
#define MV_DP_MSG_MIRROR_TUNNEL_GET_RX_SIZE		(48)

#define MV_DP_MSG_MIRROR_CFG_SET_TX_SIZE		(4)
#define MV_DP_MSG_MIRROR_CFG_SET_RX_SIZE		(0)

#define MV_DP_MSG_MIRROR_CFG_GET_TX_SIZE		(0)
#define MV_DP_MSG_MIRROR_CFG_GET_RX_SIZE		(4)

/************MIRROR Offsets**************************/
#define MV_DP_MSG_MIRROR_TUNNEL_PORT_WORD0	(0)
#define MV_DP_MSG_MIRROR_TUNNEL_PORT_OFFS	(0)
#define MV_DP_MSG_MIRROR_TUNNEL_PORT_MASK	(0x000000FF)
#define MV_DP_MSG_MIRROR_TUNNEL_PORT_SET(v)	(((v) & MV_DP_MSG_MIRROR_TUNNEL_PORT_MASK) \
						 << MV_DP_MSG_MIRROR_TUNNEL_PORT_OFFS)
#define MV_DP_MSG_MIRROR_TUNNEL_PORT_GET(v)	(((v) >> MV_DP_MSG_MIRROR_TUNNEL_PORT_OFFS) \
						 & MV_DP_MSG_MIRROR_TUNNEL_PORT_MASK)

#define MV_DP_MSG_MIRROR_TUNNEL_IPVER_WORD0	(0)
#define MV_DP_MSG_MIRROR_TUNNEL_IPVER_OFFS	(8)
#define MV_DP_MSG_MIRROR_TUNNEL_IPVER_MASK	(0x000000FF)
#define MV_DP_MSG_MIRROR_TUNNEL_IPVER_SET(v)	(((v) & MV_DP_MSG_MIRROR_TUNNEL_IPVER_MASK) \
						 << MV_DP_MSG_MIRROR_TUNNEL_IPVER_OFFS)
#define MV_DP_MSG_MIRROR_TUNNEL_IPVER_GET(v)	(((v) >> MV_DP_MSG_MIRROR_TUNNEL_IPVER_OFFS) \
						 & MV_DP_MSG_MIRROR_TUNNEL_IPVER_MASK)

#define MV_DP_MSG_MIRROR_TUNNEL_RMAC_WORD1	(1)
#define MV_DP_MSG_MIRROR_TUNNEL_RMAC_OFFS_B	(0)
#define MV_DP_MSG_MIRROR_TUNNEL_RMAC_SIZE	(6)

#define MV_DP_MSG_MIRROR_TUNNEL_LMAC_WORD2	(2)
#define MV_DP_MSG_MIRROR_TUNNEL_LMAC_OFFS_B	(2)
#define MV_DP_MSG_MIRROR_TUNNEL_LMAC_SIZE	(6)

#define MV_DP_MSG_MIRROR_TUNNEL_RIP_WORD4	(4)
#define MV_DP_MSG_MIRROR_TUNNEL_RIP_OFFS_B	(0)
#define MV_DP_MSG_MIRROR_TUNNEL_RIP_SIZE	(16)

#define MV_DP_MSG_MIRROR_TUNNEL_LIP_WORD8	(8)
#define MV_DP_MSG_MIRROR_TUNNEL_LIP_OFFS_B	(0)
#define MV_DP_MSG_MIRROR_TUNNEL_LIP_SIZE	(16)

/*CFG*/
#define MV_DP_MSG_MIRROR_CFG_TYPE_WORD0		(0)
#define MV_DP_MSG_MIRROR_CFG_TYPE_OFFS		(0)
#define MV_DP_MSG_MIRROR_CFG_TYPE_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_MIRROR_CFG_TYPE_SET(v)	(((v) & MV_DP_MSG_MIRROR_CFG_TYPE_MASK) \
						 << MV_DP_MSG_MIRROR_CFG_TYPE_OFFS)
#define MV_DP_MSG_MIRROR_CFG_TYPE_GET(v)	(((v) >> MV_DP_MSG_MIRROR_CFG_TYPE_OFFS) \
						 & MV_DP_MSG_MIRROR_CFG_TYPE_MASK)

/************MIRROR MSG END**************************/
/************QUEUE STATS COMMON***********************************
*QUEUE_STATS_GET request   -- QID
*QUEUE_STATS_GET reply     -- QUEUE_STATS fields
*
*QUEUE_CFG_RESET request   -- QID
*QUEUE_CFG_RESET reply     -- NONE
**********************************************************************/
#define MV_DP_MSG_Q_STATS_GET_TX_SIZE		(4)
#define MV_DP_MSG_Q_STATS_GET_RX_SIZE		(20)

#define MV_DP_MSG_Q_STATS_RESET_TX_SIZE		(4)
#define MV_DP_MSG_Q_STATS_RESET_RX_SIZE		(0)

/**********************************************************************/

#define MV_DP_MSG_Q_STATS_QUEUE_ID_WORD0	(0)
#define MV_DP_MSG_Q_STATS_QUEUE_ID_OFFS		(0)
#define MV_DP_MSG_Q_STATS_QUEUE_ID_MASK		(0x000000FF)
#define MV_DP_MSG_Q_STATS_QUEUE_ID_SET(v)	(((v) & MV_DP_MSG_Q_STATS_QUEUE_ID_MASK) \
									<< MV_DP_MSG_Q_STATS_QUEUE_ID_OFFS)
#define MV_DP_MSG_Q_STATS_QUEUE_ID_GET(v)	(((v) >> MV_DP_MSG_Q_STATS_QUEUE_ID_OFFS) \
									& MV_DP_MSG_Q_STATS_QUEUE_ID_MASK)

#define MV_DP_MSG_Q_STATS_PKTS_WORD1	(1)
#define MV_DP_MSG_Q_STATS_PKTS_OFFS	(0)
#define MV_DP_MSG_Q_STATS_PKTS_SIZE	(8)

#define MV_DP_MSG_Q_STATS_ERR_WORD3	(3)
#define MV_DP_MSG_Q_STATS_ERR_OFFS	(0)
#define MV_DP_MSG_Q_STATS_ERR_SIZE	(8)

/************NSS MEM DUMP MSG START******************/
/*
*NSS_MEM_WRITE request  -- ALL Fields.
*NSS_MEM_WRITE reply    -- NONE
*
*NSS_MEM_READ request   -- offset, type and size
*NSS_MEM_READ reply     -- ALL Fields including offset type and size
*
*/

#define MV_DP_MSG_NSS_MEM_DUMP_SIZE_MAX_W		(20)
#define MV_DP_MSG_NSS_MEM_DUMP_SIZE_MAX_B		(MV_DP_MSG_NSS_MEM_DUMP_SIZE_MAX_W * 4)

#define MV_DP_MSG_NSS_MEM_DUMP_SIZE_READ_W		(MV_DP_MSG_NSS_MEM_DUMP_SIZE_MAX_W)
#define MV_DP_MSG_NSS_MEM_DUMP_SIZE_READ_B		(MV_DP_MSG_NSS_MEM_DUMP_SIZE_READ_W * 4)

#define MV_DP_MSG_NSS_MEM_DUMP_SIZE_WRITE_W		(4)
#define MV_DP_MSG_NSS_MEM_DUMP_SIZE_WRITE_B		(MV_DP_MSG_NSS_MEM_DUMP_SIZE_WRITE_W * 4)


#define MV_DP_MSG_NSS_MEM_WRITE_TX_SIZE			(8 + MV_DP_MSG_NSS_MEM_DUMP_SIZE_WRITE_B)
#define MV_DP_MSG_NSS_MEM_WRITE_RX_SIZE			(0)

#define MV_DP_MSG_NSS_MEM_READ_TX_SIZE			(8)
#define MV_DP_MSG_NSS_MEM_READ_RX_SIZE			(8 + MV_DP_MSG_NSS_MEM_DUMP_SIZE_READ_B) /*up to*/

/************ Offsets**************************/
#define MV_DP_MSG_NSS_MEM_OFFSET_WORD0			(0)
#define MV_DP_MSG_NSS_MEM_OFFSET_OFFS			(0)
#define MV_DP_MSG_NSS_MEM_OFFSET_MASK			(0xFFFFFFFF)
#define MV_DP_MSG_NSS_MEM_OFFSET_SET(v)			(((v) & MV_DP_MSG_NSS_MEM_OFFSET_MASK) \
								<< MV_DP_MSG_NSS_MEM_OFFSET_OFFS)
#define MV_DP_MSG_NSS_MEM_OFFSET_GET(v)			(((v) >> MV_DP_MSG_NSS_MEM_OFFSET_OFFS) \
								& MV_DP_MSG_NSS_MEM_OFFSET_MASK)

#define MV_DP_MSG_NSS_MEM_TYPE_WORD1			(1)
#define MV_DP_MSG_NSS_MEM_TYPE_OFFS			(0)
#define MV_DP_MSG_NSS_MEM_TYPE_MASK			(0x000000FF)
#define MV_DP_MSG_NSS_MEM_TYPE_SET(v)			(((v) & MV_DP_MSG_NSS_MEM_TYPE_MASK) \
								<< MV_DP_MSG_NSS_MEM_TYPE_OFFS)
#define MV_DP_MSG_NSS_MEM_TYPE_GET(v)			(((v) >> MV_DP_MSG_NSS_MEM_TYPE_OFFS) \
								& MV_DP_MSG_NSS_MEM_TYPE_MASK)

#define MV_DP_MSG_NSS_MEM_SIZE_WORD1			(1)
#define MV_DP_MSG_NSS_MEM_SIZE_OFFS			(8)
#define MV_DP_MSG_NSS_MEM_SIZE_MASK			(0x000000FF)
#define MV_DP_MSG_NSS_MEM_SIZE_SET(v)			(((v) & MV_DP_MSG_NSS_MEM_SIZE_MASK) \
								<< MV_DP_MSG_NSS_MEM_SIZE_OFFS)
#define MV_DP_MSG_NSS_MEM_SIZE_GET(v)			(((v) >> MV_DP_MSG_NSS_MEM_SIZE_OFFS) \
								& MV_DP_MSG_NSS_MEM_SIZE_MASK)

#define MV_DP_MSG_NSS_MEM_DUMP_WORD0			(2)
#define MV_DP_MSG_NSS_MEM_DUMP_WORD0_OFF_B		(0)


/************DBG MEM DUMP MSG END**************************/

/************NSS DROP REASON STATS GET/RST MSG START******************/
/*
*MV_DP_MSGID_DBG_DROP_REASON_STATS_GET request  -- ID.
*MV_DP_MSGID_DBG_DROP_REASON_STATS_GET reply    -- ID + statistics
*MV_DP_MSGID_DBG_DROP_REASON_STATS_RST request  -- ID.
*MV_DP_MSGID_DBG_DROP_REASON_STATS_RST reply    -- NONE.
*MV_DP_MSGID_DBG_DROP_REASON_STATS_RST_ALL request  -- NONE.
*MV_DP_MSGID_DBG_DROP_REASON_STATS_RST_ALL reply    -- NONE.
*
*/
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_TX_SIZE		(4)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_GET_RX_SIZE	(4 + MV_DP_MSGID_DBG_DROP_REASON_STATS_GET_PKTS_SIZE) /*up to*/

#define MV_DP_MSGID_DBG_DROP_REASON_STATS_RST_TX_SIZE	(4)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_RST_RX_SIZE	(0)

#define MV_DP_MSGID_DBG_DROP_REASON_STATS_RST_ALL_TX_SIZE	(0)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_RST_ALL_RX_SIZE	(0)

/************ Offsets**************************/
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_WORD		(0)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_OFFS		(0)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_MASK		(0xFFFFFFFF)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_SET(v)		(((v) & MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_MASK) \
								<< MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_OFFS)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_GET(v)		(((v) >> MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_OFFS) \
								& MV_DP_MSGID_DBG_DROP_REASON_STATS_ID_MASK)

#define MV_DP_MSGID_DBG_DROP_REASON_STATS_GET_PKTS_WORD		(1)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_GET_PKTS_OFFS_B	(0)
#define MV_DP_MSGID_DBG_DROP_REASON_STATS_GET_PKTS_SIZE		(8)

/************NSS DROP REASON STATS GET/RST MSG END**************************/

/************HW QUEUE STATS COMMON***********************************
*HW_Q_STATS_GET request   -- QID
*HW_Q_STATS_GET reply     -- HW_Q_STATS fields
*
**********************************************************************/
#define MV_DP_MSG_HWQ_STATS_GET_TX_SIZE		(4)
#define MV_DP_MSG_HWQ_STATS_GET_RX_SIZE		(28)

/*********************************************************************/

#define MV_DP_MSG_HWQ_STATS_QUEUE_ID_WORD0	(0)
#define MV_DP_MSG_HWQ_STATS_QUEUE_ID_OFFS		(0)
#define MV_DP_MSG_HWQ_STATS_QUEUE_ID_MASK		(0x0000FFFF)
#define MV_DP_MSG_HWQ_STATS_QUEUE_ID_SET(v)	(((v) & MV_DP_MSG_HWQ_STATS_QUEUE_ID_MASK) \
									<< MV_DP_MSG_HWQ_STATS_QUEUE_ID_OFFS)
#define MV_DP_MSG_HWQ_STATS_QUEUE_ID_GET(v)	(((v) >> MV_DP_MSG_HWQ_STATS_QUEUE_ID_OFFS) \
									& MV_DP_MSG_HWQ_STATS_QUEUE_ID_MASK)

#define MV_DP_MSG_HWQ_STATS_ENQ_WORD1	(1)
#define MV_DP_MSG_HWQ_STATS_ENQ_OFFS	(0)
#define MV_DP_MSG_HWQ_STATS_ENQ_SIZE	(8)

#define MV_DP_MSG_HWQ_STATS_DEQ_WORD3	(3)
#define MV_DP_MSG_HwQ_STATS_DEQ_OFFS	(0)
#define MV_DP_MSG_HWQ_STATS_DEQ_SIZE	(8)

#define MV_DP_MSG_HWQ_STATS_ENQERR_WORD5 (5)
#define MV_DP_MSG_HwQ_STATS_ENQERR_OFFS	 (0)
#define MV_DP_MSG_HWQ_STATS_ENQERR_SIZE	 (8)

/************NSS HWQ STATS GET MSG END********************************/

/********************BULK GET *******************************
*  COUNT is in message HEADER
*  INDEX is the first word following the EXT HDR if ANY
********************************************************************************************************/
#define MV_DP_MSG_BULK_INDEX_WORD0		(0) /*word of index 0*/
#define MV_DP_MSG_BULK_INDEX_OFFS		(0)
#define MV_DP_MSG_BULK_INDEX_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_BULK_INDEX_GET(v)		(((v) & MV_DP_MSG_BULK_INDEX_MASK) << MV_DP_MSG_BULK_INDEX_OFFS)
#define MV_DP_MSG_BULK_INDEX_SET(v)		(((v) >> MV_DP_MSG_BULK_INDEX_OFFS) & MV_DP_MSG_BULK_INDEX_MASK)
/*******************BULK END*********************************/

/********************EVENTS*******************************
*  CODE is u32
*  TEXT is ASCII NULL Terminated string
*  FW should specify MSG size: sizeof(u32) + sizeof (TEXT) + 1 (for '\0')
**********************************************************/
#define MV_DP_MSG_EVT_RX_SIZE			(4)

#define MV_DP_MSG_EVT_CODE_WORD0		(0) /*word of index 0*/
#define MV_DP_MSG_EVT_CODE_OFFS			(0)
#define MV_DP_MSG_EVT_CODE_MASK			(0xFFFFFFFF)
#define MV_DP_MSG_EVT_CODE_GET(v)		(((v) & MV_DP_MSG_EVT_CODE_MASK) << MV_DP_MSG_EVT_CODE_OFFS)
#define MV_DP_MSG_EVT_CODE_SET(v)		(((v) >> MV_DP_MSG_EVT_CODE_OFFS) & MV_DP_MSG_EVT_CODE_MASK)


#define MV_DP_MSG_EVT_TEXT_WORD1		(1) /*first word of index 0*/
#define MV_DP_MSG_EVT_TEXT_OFFS			(0)
#define MV_DP_MSG_EVT_TEXT_MASK			(0xFFFFFFFF)
#define MV_DP_MSG_EVT_TEXT_MAX_SIZE		(MV_DP_CFH_MSG_BUF_SIZE_B - MV_DP_MSG_EVT_RX_SIZE)
#define MV_DP_MSG_EVT_TEXT_RX_SIZE		(MV_DP_MSG_EVT_TEXT_MAX_SIZE)

/*******************BULK END*********************************/



/****************EXT HDR ********************************/
/*only HDR size with out pointers both IN and OUT HDR are always present*/
#define MV_DP_EXT_BUF_CHUNK_SIZE		(4*1024)
						/*number of entities to fit into chunk*/
#define MV_DP_EXT_BUF_GET_ENTRY_COUNT(s)	(MV_DP_EXT_BUF_CHUNK_SIZE / (s))


#define MV_DP_MSG_EXT_HDR_PTR_SIZE		(4)
#define MV_DP_MSG_EXT_HDR_IN_SIZE		(8)
#define MV_DP_MSG_EXT_HDR_OUT_SIZE		(8)
#define MV_DP_MSG_EXT_HDR_SIZE_B		(MV_DP_MSG_EXT_HDR_IN_SIZE + MV_DP_MSG_EXT_HDR_OUT_SIZE)

#define MV_DP_MSG_EXT_HDR_SIZE_W		((MV_DP_MSG_EXT_HDR_SIZE_B)/4)


#define MV_DP_EXT_BUF_GET_CHUNK_COUNT(num, each) (DIV_ROUND_UP((num), MV_DP_EXT_BUF_GET_ENTRY_COUNT(each)))

#ifdef MV_DP_USE_DRAM_PTR
#define MV_DP_MSG_EXT_HDR_MAX_PTR		(MV_DP_EXT_BUF_CHUNK_SIZE / MV_DP_MSG_EXT_HDR_PTR_SIZE)
#define MV_DP_MSG_EXT_HDR_SIZE_CALC_B(s)	(MV_DP_MSG_EXT_HDR_SIZE_B + MV_DP_MSG_EXT_HDR_PTR_SIZE)
#define MV_DP_MSG_EXT_HDR_SIZE_CALC_W(s)	(MV_DP_MSG_EXT_HDR_SIZE_CALC_B((s)) / 4)
#else
#define MV_DP_MSG_EXT_HDR_MAX_PTR		((MV_DP_CFH_MSG_BUF_SIZE_B - MV_DP_MSG_EXT_HDR_SIZE_B) \
						/ MV_DP_MSG_EXT_HDR_PTR_SIZE)
#define MV_DP_MSG_EXT_HDR_SIZE_CALC_B(s)	(MV_DP_MSG_EXT_HDR_SIZE_B + (s) * MV_DP_MSG_EXT_HDR_PTR_SIZE)
#define MV_DP_MSG_EXT_HDR_SIZE_CALC_W(s)	(MV_DP_MSG_EXT_HDR_SIZE_CALC_B((s)) / 4)
#endif



/****************EXT HDR FIELDS OFFSETS******************************************************/
#define MV_DP_MSG_EXT_HDR_IN_FLAG_REUSE		(0x01)

#define MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_WORD0	(0)
#define MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_OFFS	(0)
#define MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_MASK	(0x00FFFFFF)
#define MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_SET(v)	(((v) & MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_MASK) \
										<< MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_OFFS)
#define MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_GET(v)	(((v) >> MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_OFFS) \
										& MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_MASK)

#define MV_DP_MSG_EXT_HDR_IN_FLAGS_WORD0	(0)
#define MV_DP_MSG_EXT_HDR_IN_FLAGS_OFFS		(24)
#define MV_DP_MSG_EXT_HDR_IN_FLAGS_MASK		(0x000000FF)
#define MV_DP_MSG_EXT_HDR_IN_FLAGS_SET(v)	(((v) & MV_DP_MSG_EXT_HDR_IN_FLAGS_MASK) \
										<< MV_DP_MSG_EXT_HDR_IN_FLAGS_OFFS)
#define MV_DP_MSG_EXT_HDR_IN_FLAGS_GET(v)	(((v) >> MV_DP_MSG_EXT_HDR_IN_FLAGS_OFFS) \
										& MV_DP_MSG_EXT_HDR_IN_FLAGS_MASK)


#define MV_DP_MSG_EXT_HDR_IN_NUM_WORD1		(1)
#define MV_DP_MSG_EXT_HDR_IN_NUM_OFFS		(16)
#define MV_DP_MSG_EXT_HDR_IN_NUM_MASK		(0x0000FFFF)
#define MV_DP_MSG_EXT_HDR_IN_NUM_SET(v)		(((v) & MV_DP_MSG_EXT_HDR_IN_NUM_MASK) << MV_DP_MSG_EXT_HDR_IN_NUM_OFFS)
#define MV_DP_MSG_EXT_HDR_IN_NUM_GET(v)		(((v) >> MV_DP_MSG_EXT_HDR_IN_NUM_OFFS) & MV_DP_MSG_EXT_HDR_IN_NUM_MASK)

#define MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_WORD1	(1)
#define MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_OFFS	(0)
#define MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_MASK	(0x0000FFFF)
#define MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_SET(v)	(((v) & MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_MASK) \
										<< MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_OFFS)
#define MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_GET(v)	(((v) >> MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_OFFS) \
										& MV_DP_MSG_EXT_HDR_IN_CHUNK_SIZE_MASK)

#define MV_DP_MSG_EXT_HDR_OUT_TOTAL_SIZE_WORD2	(2)
#define MV_DP_MSG_EXT_HDR_OUT_TOTAL_SIZE_OFFS	(0)
#define MV_DP_MSG_EXT_HDR_OUT_TOTAL_SIZE_MASK	(0x00FFFFFF)
#define MV_DP_MSG_EXT_HDR_OUT_TOTAL_SIZE_SET(v)	(((v) & MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_MASK) \
										<< MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_OFFS)
#define MV_DP_MSG_EXT_HDR_OUT_TOTAL_SIZE_GET(v)	(((v) >> MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_OFFS) \
										& MV_DP_MSG_EXT_HDR_IN_TOTAL_SIZE_MASK)

#define MV_DP_MSG_EXT_HDR_OUT_FLAGS_WORD2	(2)
#define MV_DP_MSG_EXT_HDR_OUT_FLAGS_OFFS	(24)
#define MV_DP_MSG_EXT_HDR_OUT_FLAGS_MASK	(0x000000FF)
#define MV_DP_MSG_EXT_HDR_OUT_FLAGS_SET(v)	(((v) & MV_DP_MSG_EXT_HDR_OUT_FLAGS_MASK) \
										<< MV_DP_MSG_EXT_HDR_OUT_FLAGS_OFFS)
#define MV_DP_MSG_EXT_HDR_OUT_FLAGS_GET(v)	(((v) >> MV_DP_MSG_EXT_HDR_OUT_FLAGS_OFFS) \
										& MV_DP_MSG_EXT_HDR_OUT_FLAGS_MASK)


#define MV_DP_MSG_EXT_HDR_OUT_NUM_WORD3		(3)
#define MV_DP_MSG_EXT_HDR_OUT_NUM_OFFS		(16)
#define MV_DP_MSG_EXT_HDR_OUT_NUM_MASK		(0x0000FFFF)
#define MV_DP_MSG_EXT_HDR_OUT_NUM_SET(v)	(((v) & MV_DP_MSG_EXT_HDR_OUT_NUM_MASK) \
						<< MV_DP_MSG_EXT_HDR_OUT_NUM_OFFS)
#define MV_DP_MSG_EXT_HDR_OUT_NUM_GET(v)	(((v) >> MV_DP_MSG_EXT_HDR_OUT_NUM_OFFS) \
						& MV_DP_MSG_EXT_HDR_OUT_NUM_MASK)

#define MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_WORD3	(3)
#define MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_OFFS	(0)
#define MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_MASK	(0x0000FFFF)
#define MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_SET(v)	(((v) & MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_MASK) \
									<< MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_OFFS)
#define MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_GET(v)	(((v) >> MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_OFFS) \
									& MV_DP_MSG_EXT_HDR_OUT_CHUNK_SIZE_MASK)


#define MV_DP_MSG_EXT_HDR_PTR_WORD		(4)
#define MV_DP_MSG_EXT_HDR_PTR_OFFS		(0)
#define MV_DP_MSG_EXT_HDR_PTR_MASK		(0xFFFFFFFF)
#define MV_DP_MSG_EXT_HDR_PTR_SET(v)		(((u64)(v) & MV_DP_MSG_EXT_HDR_PTR_MASK) \
										<< MV_DP_MSG_EXT_HDR_PTR_OFFS)
#define MV_DP_MSG_EXT_HDR_PTR_GET(v)		((((u64)(v) >> MV_DP_MSG_EXT_HDR_PTR_OFFS) \
										& MV_DP_MSG_EXT_HDR_PTR_MASK))


#ifdef __cplusplus
}
#endif
#endif

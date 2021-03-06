/*
 * drivers/target/iscsi/iscsi_target.h
 *
 * Copyright (c) 2016 Allwinnertech Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#ifndef ISCSI_TARGET_H
#define ISCSI_TARGET_H

extern struct iscsi_tiqn *iscsit_get_tiqn_for_login(unsigned char *);
extern struct iscsi_tiqn *iscsit_get_tiqn(unsigned char *, int);
extern void iscsit_put_tiqn_for_login(struct iscsi_tiqn *);
extern struct iscsi_tiqn *iscsit_add_tiqn(unsigned char *);
extern void iscsit_del_tiqn(struct iscsi_tiqn *);
extern int iscsit_access_np(struct iscsi_np *, struct iscsi_portal_group *);
extern int iscsit_deaccess_np(struct iscsi_np *, struct iscsi_portal_group *);
extern struct iscsi_np *iscsit_add_np(struct __kernel_sockaddr_storage *,
				char *, int);
extern int iscsit_reset_np_thread(struct iscsi_np *, struct iscsi_tpg_np *,
				struct iscsi_portal_group *);
extern int iscsit_del_np(struct iscsi_np *);
extern int iscsit_add_reject_from_cmd(u8, int, int, unsigned char *, struct iscsi_cmd *);
extern int iscsit_logout_closesession(struct iscsi_cmd *, struct iscsi_conn *);
extern int iscsit_logout_closeconnection(struct iscsi_cmd *, struct iscsi_conn *);
extern int iscsit_logout_removeconnforrecovery(struct iscsi_cmd *, struct iscsi_conn *);
extern int iscsit_send_async_msg(struct iscsi_conn *, u16, u8, u8);
extern int iscsit_send_r2t(struct iscsi_cmd *, struct iscsi_conn *);
extern int iscsit_build_r2ts_for_cmd(struct iscsi_cmd *, struct iscsi_conn *, int);
extern void iscsit_thread_get_cpumask(struct iscsi_conn *);
extern int iscsi_target_tx_thread(void *);
extern int iscsi_target_rx_thread(void *);
extern int iscsit_close_connection(struct iscsi_conn *);
extern int iscsit_close_session(struct iscsi_session *);
extern void iscsit_fail_session(struct iscsi_session *);
extern int iscsit_free_session(struct iscsi_session *);
extern void iscsit_stop_session(struct iscsi_session *, int, int);
extern int iscsit_release_sessions_for_tpg(struct iscsi_portal_group *, int);

extern struct iscsit_global *iscsit_global;
extern struct target_fabric_configfs *lio_target_fabric_configfs;

extern struct kmem_cache *lio_dr_cache;
extern struct kmem_cache *lio_ooo_cache;
extern struct kmem_cache *lio_cmd_cache;
extern struct kmem_cache *lio_qr_cache;
extern struct kmem_cache *lio_r2t_cache;

#endif   /*** ISCSI_TARGET_H ***/

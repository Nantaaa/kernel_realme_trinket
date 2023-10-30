/*******************************************************************************
** Copyright (C), 2008-2016, OPPO Mobile Comm Corp., Ltd.
** CONFIG_ODM_WT_EDIT
** FILE: - ilitek
** Description : This program is for usb notifier
** Version: 1.0
** Date : 2018/11/27
** Author: Zhonghua Hu@ODM_WT.BSP.TP-FP.TP
**
** -------------------------Revision History:----------------------------------
**  <author>	 <data> 	<version >			<desc>
**
**
*******************************************************************************/

#include <linux/notifier.h>
#include <linux/usb_notifier.h>

ATOMIC_NOTIFIER_HEAD(usb_notifier_list);
EXPORT_SYMBOL_GPL(usb_notifier_list);

int usb_register_client(struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&usb_notifier_list, nb);

}
EXPORT_SYMBOL(usb_register_client);

int usb_unregister_client(struct notifier_block *nb)
{
	return atomic_notifier_chain_unregister(&usb_notifier_list, nb);
}
EXPORT_SYMBOL(usb_unregister_client);


int usb_notifier_call_chain(unsigned long val, void *v)
{
	return atomic_notifier_call_chain(&usb_notifier_list, val, v);

}
EXPORT_SYMBOL_GPL(usb_notifier_call_chain);



#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x405fe887, "module_layout" },
	{ 0xbb8f731c, "usb_register_driver" },
	{ 0x3ec6c705, "kmalloc_caches" },
	{ 0xc66794ea, "usb_register_dev" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x9bdae3e3, "usb_get_dev" },
	{ 0xf6288e02, "__init_waitqueue_head" },
	{ 0xdc798d37, "__mutex_init" },
	{ 0x5f754e5a, "memset" },
	{ 0x83800bfa, "kref_init" },
	{ 0x6b1e3028, "kmem_cache_alloc" },
	{ 0x37a0cba, "kfree" },
	{ 0x66a10c0e, "usb_put_dev" },
	{ 0x6f3d8ffc, "dev_driver_string" },
	{ 0x509023eb, "usb_deregister_dev" },
	{ 0x3b810932, "dev_set_drvdata" },
	{ 0x60f71cfa, "complete" },
	{ 0x98082893, "__copy_to_user" },
	{ 0x5baaba0, "wait_for_completion" },
	{ 0xec6a4d04, "wait_for_completion_interruptible" },
	{ 0x2700b38a, "mutex_lock_interruptible" },
	{ 0xc97912fa, "usb_free_urb" },
	{ 0xe54b3c34, "usb_unanchor_urb" },
	{ 0xe7024016, "usb_anchor_urb" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x17a142df, "__copy_from_user" },
	{ 0xc9b17579, "usb_alloc_coherent" },
	{ 0x1ed71d42, "usb_alloc_urb" },
	{ 0x448212fa, "down_trylock" },
	{ 0xc9161a57, "down_interruptible" },
	{ 0x8cf51d15, "up" },
	{ 0x579043f7, "usb_free_coherent" },
	{ 0x711cc5f9, "usb_submit_urb" },
	{ 0xd2c895c2, "usb_autopm_get_interface" },
	{ 0x9775cdc, "kref_get" },
	{ 0xea147363, "printk" },
	{ 0x3c751e61, "usb_find_interface" },
	{ 0x43b0c9c3, "preempt_schedule" },
	{ 0xd5b037e1, "kref_put" },
	{ 0xde514062, "usb_autopm_put_interface" },
	{ 0xe16b893b, "mutex_lock" },
	{ 0xa561daec, "usb_kill_urb" },
	{ 0xee6446bd, "usb_kill_anchored_urbs" },
	{ 0xd9eef782, "usb_wait_anchor_empty_timeout" },
	{ 0x62b72b0d, "mutex_unlock" },
	{ 0x122af8d0, "dev_get_drvdata" },
	{ 0x64b64f20, "usb_deregister" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:vFFF0pFFF0d*dc*dsc*dp*ic*isc*ip*");

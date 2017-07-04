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
	{ 0x9c3f02a1, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x52faeb59, __VMLINUX_SYMBOL_STR(noop_llseek) },
	{ 0x373c514d, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x69b610f4, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0xb2c3d99f, __VMLINUX_SYMBOL_STR(usb_unanchor_urb) },
	{ 0xbba8f431, __VMLINUX_SYMBOL_STR(usb_anchor_urb) },
	{ 0x362ef408, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x814296ae, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0x44f1606d, __VMLINUX_SYMBOL_STR(down_trylock) },
	{ 0x4792c572, __VMLINUX_SYMBOL_STR(down_interruptible) },
	{ 0x2f287f0d, __VMLINUX_SYMBOL_STR(copy_to_user) },
	{ 0x75bb675a, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x622fa02a, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0x4292364c, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x8e91e17f, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x5b334567, __VMLINUX_SYMBOL_STR(mutex_lock_interruptible) },
	{ 0x59bdfef1, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0x8ff4079b, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0xf1faac3a, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0xa0f54941, __VMLINUX_SYMBOL_STR(usb_autopm_put_interface) },
	{ 0xbbf141cd, __VMLINUX_SYMBOL_STR(usb_deregister_dev) },
	{ 0xfa774f26, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x5aab920e, __VMLINUX_SYMBOL_STR(usb_register_dev) },
	{ 0x4e270e4f, __VMLINUX_SYMBOL_STR(dev_set_drvdata) },
	{ 0xb1bd3dcc, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x201335de, __VMLINUX_SYMBOL_STR(usb_get_dev) },
	{ 0x68dfc59f, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x3f6880ab, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0xba966047, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x43a69ab4, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xe91b46b6, __VMLINUX_SYMBOL_STR(usb_put_dev) },
	{ 0x512d53b1, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0xe45f60d8, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x6483b924, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xc4554217, __VMLINUX_SYMBOL_STR(up) },
	{ 0xaf002bfd, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0x76ebea8, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0x67f7403e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x9c860aa2, __VMLINUX_SYMBOL_STR(usb_autopm_get_interface) },
	{ 0x49b83936, __VMLINUX_SYMBOL_STR(usb_find_interface) },
	{ 0xb988d7d7, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x11d937eb, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0x8c4db1b5, __VMLINUX_SYMBOL_STR(usb_kill_anchored_urbs) },
	{ 0xeec24d31, __VMLINUX_SYMBOL_STR(usb_wait_anchor_empty_timeout) },
	{ 0x414f988b, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x4784cb4c, __VMLINUX_SYMBOL_STR(dev_get_drvdata) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v1483p5751d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "B788228DA95C5F76BBD8E61");

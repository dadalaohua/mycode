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
	{ 0x3c2c5af5, "sprintf" },
	{ 0x32184e52, "create_proc_entry" },
	{ 0x9f0f26dc, "proc_mkdir" },
	{ 0x75d5680c, "misc_register" },
	{ 0xbf42b7f, "misc_deregister" },
	{ 0x22082c5f, "remove_proc_entry" },
	{ 0x98082893, "__copy_to_user" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x17a142df, "__copy_from_user" },
	{ 0xea147363, "printk" },
	{ 0x43b0c9c3, "preempt_schedule" },
	{ 0xd49c12f1, "module_put" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


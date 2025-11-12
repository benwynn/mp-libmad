#include "py/dynruntime.h"

static mp_obj_t hello(mp_obj_t in) {
  const char *world = mp_obj_str_get_str(in);
  mp_printf(&mp_plat_print, "Hello %s", world);
  return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(hello_obj, hello);

mp_obj_t mpy_init(mp_obj_fun_bc_t *self, size_t n_args, size_t n_kw, mp_obj_t *args) {
  MP_DYNRUNTIME_INIT_ENTRY

  // add function calls here
  mp_store_global(MP_QSTR_hello, MP_OBJ_FROM_PTR(&hello_obj));

  MP_DYNRUNTIME_INIT_EXIT
}

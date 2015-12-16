#include <libnvpair.h>
#include <zone.h>

#include "v8plus_glue.h"

/*
 * Primary entrypoint from Javascript:
 */
static nvlist_t *
zonename_zonename(const nvlist_t *ap)
{
	(void) ap;

	nvlist_t *ret = NULL;
	zoneid_t zoneid;
	char zonename[ZONENAME_MAX];

	if (nvlist_alloc(&ret, NV_UNIQUE_NAME, 0) != 0)
		return (v8plus_error(V8PLUSERR_UNKNOWN, "nvlist_alloc"));

	zoneid = getzoneid();

	if (getzonenamebyid(zoneid, zonename, sizeof (zonename)) < 0)
		return (v8plus_error(V8PLUSERR_UNKNOWN, "getzonenamebyid"));

	if (nvlist_add_string(ret, "res", zonename) != 0)
		return (v8plus_error(V8PLUSERR_UNKNOWN, "nvlist_add_string"));

	return ret;
}

/*
 * v8plus Boilerplate
 */
const v8plus_c_ctor_f v8plus_ctor = NULL;
const v8plus_c_dtor_f v8plus_dtor = NULL;
const char *v8plus_js_factory_name = NULL;
const char *v8plus_js_class_name = NULL;

const v8plus_method_descr_t v8plus_methods[] = {};
const uint_t v8plus_method_count =
    sizeof (v8plus_methods) / sizeof (v8plus_methods[0]);

const v8plus_static_descr_t v8plus_static_methods[] = {
	{
		sd_name: "zonename",
		sd_c_func: zonename_zonename
	}
};
const uint_t v8plus_static_method_count =
    sizeof (v8plus_static_methods) / sizeof (v8plus_static_methods[0]);

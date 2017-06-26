/*-
 * Copyright (c) 2015 Varnish Software
 * All rights reserved.
 *
 * Author: Stephan Doliov <stephandoliov@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <uuid/uuid.h>
#include <string.h>

#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"

#include "vcc_uuid_if.h"

int rand_seeded = 0;

/*
struct urandom {
    FILE *f;
    int rand_seeded;
}

static void
vmod_free(void *priv)
{
}


VCL_VOID __match_proto__()
vmod_register_obj_events(VRT_CTX, struct vmod_priv *priv)
{
        struct priv_vcl *priv_vcl;

        CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
        CAST_OBJ_NOTNULL(priv_vcl, priv->priv, PRIV_VCL_MAGIC);
        AZ(priv_vcl->obj_cb);
        priv_vcl->obj_cb = ObjSubscribeEvents(obj_cb, priv_vcl,
                OEV_INSERT|OEV_EXPIRE);
        VSL(SLT_Debug, 0, "Subscribed to Object Events");
}

*/

VCL_VOID
vmod_seed_random(VRT_CTX)
{
    (void)ctx;
    srandom((unsigned)time(NULL));
    rand_seeded = 1;
}

VCL_STRING
vmod_get_rand_uuid(VRT_CTX)
{

    char *output;
    uuid_t uuid;
    uuid_generate_random(uuid);
    char uuid_hex[37];
    uuid_unparse_lower(uuid,uuid_hex);
    output = WS_Copy(ctx->ws,uuid_hex,37);
    return (output);

}

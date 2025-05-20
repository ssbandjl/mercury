/**
 * Copyright (c) 2013-2022 UChicago Argonne, LLC and The HDF Group.
 * Copyright (c) 2022-2023 Intel Corporation.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "example_rpc.h"
#include "example_rpc_engine.h"

#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <sys/syscall.h>


/* Debug with thread_id, function_name, file, line */
#define dbg(format, arg...)							\
	printf("tid:%ld, %s(), %s:%d, " format,					\
		syscall(SYS_gettid), __FUNCTION__, __FILE__, __LINE__, ##arg)

/* example server program.  Starts HG engine, registers the example RPC type,
 * and then executes indefinitely.
 */

int
main(int argc, char *argv[])
{
	char *provider = "tcp://:12345";

	if (argc > 1) {
		dbg("provider:%s\n", argv[1]);
		hg_engine_init(HG_TRUE, argv[1]);
	}
	else
    	hg_engine_init(HG_TRUE, provider);

    hg_engine_print_self_addr();

    /* register RPC */
    my_rpc_register();

    /* this would really be something waiting for shutdown notification */
    while (1)
        sleep(1);

    hg_engine_finalize();

	if (provider)
		free(provider);
    return (0);
}

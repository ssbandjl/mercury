/*
 * @Author: xb ssbandjl@163.com
 * @Date: 2023-09-19 08:19:04
 * @LastEditors: xb ssbandjl@163.com
 * @LastEditTime: 2023-09-19 08:57:08
 * @FilePath: /mercury/mercury/05_bulk/types.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef PARAM_H
#define PARAM_H

#include <mercury.h>
#include <mercury_bulk.h>
#include <mercury_proc_string.h>
#include <mercury_macros.h>

MERCURY_GEN_PROC(save_in_t,
    ((hg_string_t)(filename))\
	((hg_size_t)(size))\
    ((hg_bulk_t)(bulk_handle)))

MERCURY_GEN_PROC(save_out_t, ((int32_t)(ret)))

#endif

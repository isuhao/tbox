/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2017, ruki All rights reserved.
 *
 * @author      ruki
 * @file        scheduler.h
 *
 */
#ifndef TB_COROUTINE_IMPL_STACKLESS_SCHEDULER_H
#define TB_COROUTINE_IMPL_STACKLESS_SCHEDULER_H

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "coroutine.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_enter__

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/// the stackless coroutine scheduler type
typedef struct __tb_lo_scheduler_t
{
    // is stopped
    tb_bool_t                       stopped;

    // the running coroutine
    tb_lo_coroutine_t*              running;

    // the dead coroutines
    tb_list_entry_head_t            coroutines_dead;

    /* the ready coroutines
     * 
     * ready: head -> ready -> .. -> running -> .. -> ready -> ..->
     *         |                                                   |
     *          ---------------------------<-----------------------
     */
    tb_list_entry_head_t            coroutines_ready;

    // the suspend coroutines
    tb_list_entry_head_t            coroutines_suspend;

}tb_lo_scheduler_t;

/* //////////////////////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! start coroutine 
 *
 * @param scheduler     the scheduler (can not be null)
 * @param func          the coroutine function
 * @param priv          the passed user private data as the argument of function
 *
 * @return              tb_true or tb_false
 */
tb_bool_t               tb_lo_scheduler_start(tb_lo_scheduler_ref_t scheduler, tb_lo_coroutine_func_t func, tb_cpointer_t priv);

/* //////////////////////////////////////////////////////////////////////////////////////
 * extern
 */
__tb_extern_c_leave__

#endif

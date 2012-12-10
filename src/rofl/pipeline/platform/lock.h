#ifndef __PLATFORM_LOCK_H__
#define __PLATFORM_LOCK_H__

#include "../util/rofl_pipeline_utils.h"

/*
*
* Header file containing a platform agnostic locking interface 
*      Author: msune
*
*/

#include "platform_lock.h"

//C++ extern C
ROFL_PIPELINE_BEGIN_DECLS

/* MUTEX operations */
//Init&destroy
int platform_mutex_init(platform_mutex_t* mutex, void* params);
void platform_mutex_destroy(platform_mutex_t* mutex);

//Operations
void platform_mutex_lock(platform_mutex_t* mutex);
void platform_mutex_unlock(platform_mutex_t* mutex);

/* RWLOCK */
//Init&destroy
int platform_rwlock_init(platform_rwlock_t* rwlock, void* params);
void platform_rwlock_destroy(platform_rwlock_t* rwlock);

//Read
void platform_rwlock_rdlock(platform_rwlock_t* rwlock);
void platform_rwlock_rdunlock(platform_rwlock_t* rwlock);

//Write
void platform_rwlock_wrlock(platform_rwlock_t* rwlock);
void platform_rwlock_wrunlock(platform_rwlock_t* rwlock);

//C++ extern C
ROFL_PIPELINE_END_DECLS

#endif //PLATFORM_LOCK
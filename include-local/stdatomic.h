#pragma once

enum memory_order {
    memory_order_releaxed = __ATOMIC_RELAXED,
    memory_order_consume = __ATOMIC_CONSUME,
    memory_order_release = __ATOMIC_RELEASE,
    memory_order_acquire = __ATOMIC_ACQUIRE,
    memory_order_acq_rel = __ATOMIC_ACQ_REL,
    memory_order_seq_cst = __ATOMIC_SEQ_CST
}

#define atomic_exchange_explicit(PTR, VAL, MO)				\
  ({									\
    __auto_type __atomic_exchange_ptr = (PTR);				\
    __typeof__ ((void)0, *__atomic_exchange_ptr) __atomic_exchange_val = (VAL);	\
    __typeof__ ((void)0, *__atomic_exchange_ptr) __atomic_exchange_tmp;		\
    __atomic_exchange (__atomic_exchange_ptr, &__atomic_exchange_val,	\
		       &__atomic_exchange_tmp, (MO));			\
    __atomic_exchange_tmp;						\
  })

#define atomic_store_explicit(PTR, VAL, MO)				\
  ({									\
    __auto_type __atomic_store_ptr = (PTR);				\
    __typeof__ ((void)0, *__atomic_store_ptr) __atomic_store_tmp = (VAL);	\
    __atomic_store (__atomic_store_ptr, &__atomic_store_tmp, (MO));	\
  })


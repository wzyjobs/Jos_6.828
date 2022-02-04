# Exercise
#### Exercise 1
```
[Steps]
1. In the file kern/pmap.c, you must implement code for the following functions (probably in the order given).

    boot_alloc()
    mem_init() (only up to the call to check_page_free_list(1))
    page_init()
    page_alloc()
    page_free()

check_page_free_list() and check_page_alloc() test your physical page allocator. You should boot JOS and see whether check_page_alloc() reports success. Fix your code so that it passes. You may find it helpful to add your own assert()s to verify that your assumptions are correct.

[What should i learn in this exercise ?]
1. Physical Page Management

[Questions]
N/A
```
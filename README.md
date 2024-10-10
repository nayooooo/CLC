# CLC(Class List Container)

类式链表容器

[使用示例（usage example）](https://github.com/nayooooo/FuzzyControl/blob/master/test/Core/Core/main.c)

类式链表容器能够存放各种类型的数据，在实际结构中使用`void* data`指针进行管理。

    struct list
    {
        void *data;
        struct list *next;
    };

由于`list.data`是`void*`类型，没办法在指针中对数据进行更多的操作，因此需要使用时传入谓词或事件回调函数等对数据进行操作。

## 谓词和事件回调函数指针

| 名称 | 参数 | 返回值 | 描述 |
| - | - | - | - |
| list_pred | list_node,void* | bool | 谓词，通常用于确定是否是指定节点，也可对节点数据进行操作 |
| list_node_data_construct_cb | void* | bool | 节点数据构造函数 |
| list_node_data_deconstruct_cb | void* | bool | 节点数据析构函数 |
| list_event_cb | list_node,void* | bool | 事件回调函数，可用于操作节点数据 |

## 默认谓词和回调函数

| 名称 | 参数 | 返回值 | 描述 |
| - | - | - | - |
| list_pred_true | list_node,void* | bool | 默认真谓词 |
| list_pred_false | list_node,void* | bool | 默认假谓词 |

## 链表操作API

| 名称 | 参数 | 返回值 | 描述 |
| - | - | - | - |
| list_create | - | list_head | 创建链表句柄（头节点） |
| list_clear | list_head,list_node_data_deconstruct_cb | bool | 清空链表中的节点 |
| list_delete | list_head,list_node_data_deconstruct_cb | bool | 删除链表（包括链表中的节点和链表头节点） |
| list_length | list_head | list_index | 获取链表长度（链表中的节点数） |

## 链表节点操作API

| 名称 | 参数 | 返回值 | 描述 |
| - | - | - | - |
| list_node_is_on_list | list_head,list_node | bool | 判断节点是否在链表上 |
| list_find_prev_node | list_head,list_node | list_node | 查找链表中指定节点的前一个节点 |
| list_find_next_node | list_head,list_node | list_node | 查找链表中指定节点的后一个节点 |
| list_push | list_head,void*,size_t | bool | 向链表的尾部追加一个节点 |
| list_pop | list_head | bool | 将链表末尾的节点删除 |
| list_find_if | list_head,void*,list_pred | list_node | 在链表中查找符合条件的第一个节点 |
| list_push_if | list_head,void*,size_t,list_pred,list_node_data_construct_cb | bool | 向链表的尾部追加一个节点，要求追加节点前的链表的最后一个节点满足谓词的要求，如果需要构造节点数据，则需传入构造函数指针 |
| list_pop_if | list_head,void*,list_pred,list_node_data_deconstruct_cb | bool | 将链表末尾的节点删除，要求删除节点前的链表的最后一个节点满足谓词的要求，如果需要析构节点数据，则需传入析构函数指针 |
| list_remove_if | list_head,void*,list_pred,list_node_data_deconstruct_cb | bool | 移除链表中符合谓词要求的节点，要求将被删除的节点链接在链表中，如果需要析构节点数据，则需传入析构函数指针 |
| list_swap_if | list_head,void*,void*,list_pred,list_pred | bool | 交换两个节点的逻辑位置，要求两个节点都在链表中，特殊地，要求交换的节点是链表中的同一个节点也能交换 |
| list_trav | list_head,void*,list_event_cb | bool | 遍历链表中的节点，并通过事件回调函数执行用户操作 |

## 参数获取API

| 名称 | 参数 | 返回值 | 描述 |
| - | - | - | - |
| list_get_first_node | list_head | list_node | 获取链表中的第一个节点，如果链表是空的，则返回`nullptr` |
| list_get_last_node | list_head | list_node | 获取链表中的最后一个节点，如果链表是空的，则返回`nullptr` |
| list_get_node_data | list_head,list_index | void* | 获取指定索引处节点的数据 |
| list_get_node_data_if | list_head,void*,list_pred | void* | 获取满足谓词描述的节点的数据 |

#include "ngx_xdemo.h"

ngx_int_t 
ngx_xdemo_handler(ngx_http_request_t* rq)
{
    ngx_int_t    rc;
    ngx_buf_t   *b;
    ngx_chain_t  out;
    rq->headers_out.content_type.len = sizeof("text/html") - 1;
    rq->headers_out.content_type.data = (u_char *) "text/html";
    b = ngx_pcalloc(rq->pool, sizeof(ngx_buf_t));
    if (b == NULL) 
    {
        return NGX_HTTP_INTERNAL_SERVER_ERROR;
    }
    out.buf = b;
    out.next = NULL;
    b->pos = ngx_xdemo_string;
    b->last = ngx_xdemo_string + sizeof(ngx_xdemo_string) - 1; /* the end offset of the buffer */
    b->memory = 1;    /* this buffer is in memory */
    b->last_buf = 1;  /* this is the last buffer in the buffer chain */
    /* 设置http返回码 */
    rq->headers_out.status = NGX_HTTP_OK;
    rq->headers_out.content_length_n = sizeof(ngx_xdemo_string) - 1;
    //发送HTTP报头
    /* send the headers of your response */
    rc = ngx_http_send_header(rq);
    if (rc == NGX_ERROR || rc > NGX_OK || rq->header_only) 
    {
        return rc;
    }
    //输出内容
    /* send the buffer chain of your response */
    return ngx_http_output_filter(rq, &out);
}

char* 
ngx_xdemo_setup(
  ngx_conf_t *cf, 
  ngx_command_t * cmd,
  void *conf
)
{
    ngx_http_core_loc_conf_t *clcf;

    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_xdemo_handler; /* handler to process the ‘hello’ directive */

    return NGX_CONF_OK;
}

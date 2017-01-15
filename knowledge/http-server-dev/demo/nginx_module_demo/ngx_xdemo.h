#ifndef NGX_XDEMO_H
#define NGX_XDEMO_H

#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>


u_char
ngx_xdemo_string[] = "Hello nginx module demo.";

static char*
ngx_xdemo_setup(ngx_conf_t *cf, ngx_command_t * cmd, void* conf);

static ngx_command_t
ngx_xdemo_commands[] =
{
  {
    ngx_string("ngx_demo"),
    NGX_HTTP_LOC_CONF | NGX_CONF_NOARGS,
    ngx_xdemo_setup,
    0,
    0,
    NULL
  },
  ngx_null_command
};

static ngx_http_module_t ngx_xdemo_ctx = 
{
  NULL,                          /* preconfiguration */
  NULL,                          /* postconfiguration */
  NULL,                          /* create main configuration */
  NULL,                          /* init main configuration */
  NULL,                          /* create server configuration */
  NULL,                          /* merge server configuration */
  NULL,                          /* create location configuration */
  NULL                           /* merge location configuration */
};

ngx_module_t
ngx_xdemo = 
{
  NGX_MODULE_V1,
  &ngx_xdemo_ctx,       /* module context */
  ngx_xdemo_commands,   /* module directives */
  NGX_HTTP_MODULE,      /* module type */
  NULL,                 /* init master */
  NULL,                 /* init module */
  NULL,                 /* init process */
  NULL,                 /* init thread */
  NULL,                 /* exit thread */
  NULL,                 /* exit process */
  NULL,                 /* exit master */
 NGX_MODULE_V1_PADDING
};

static ngx_int_t
ngx_xdemo_handler(ngx_http_request_t* rq);

#endif

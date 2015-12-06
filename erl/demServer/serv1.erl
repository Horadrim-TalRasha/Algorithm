-module(serv1).
-export([start/0]).

start() -> spawn(fun() -> loop() end).


loop() ->
    receive
        {callback, From, Request} ->
%            io:format("serv1, ~p ~p~n", [From, Request]),
            io:format("serv1, ~p~n", [Request]),
            loop()
    end.

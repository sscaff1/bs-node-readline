type t;

[@bs.deriving abstract]
type interfaceOptions = {
  input: in_channel,
  [@bs.optional]
  output: out_channel,
  [@bs.optional]
  terminal: bool,
  [@bs.optional]
  historySize: int,
  [@bs.optional]
  prompt: string,
  [@bs.optional]
  crlfDelay: int,
  [@bs.optional]
  removeHistoryDuplicates: int,
};

[@bs.module "readline"] external createInterface : interfaceOptions => t = "";

[@bs.send]
external on :
  (
    t,
    [@bs.string] [
      | `close(unit => unit)
      | `line(string => unit)
      | `pause(unit => unit)
      | `resume(unit => unit)
      | `SIGCONT(unit => unit)
      | `SIGINT(unit => unit)
      | `SIGTSTP(unit => unit)
    ]
  ) =>
  t =
  "";

[@bs.send] external close : t => unit = "";

[@bs.send] external pause : t => unit = "";

[@bs.send] external prompt : (t, ~preserveCursor: bool=?, unit) => unit = "";

[@bs.send] external question : (t, string, string => unit) => unit = "";

[@bs.send] external resume : t => unit = "";

[@bs.send] external setPrompt : (t, string) => unit = "";

[@bs.deriving abstract]
type keyOption = {
  [@bs.optional]
  ctrl: bool,
  [@bs.optional]
  meta: bool,
  [@bs.optional]
  shift: bool,
  name: string,
};

[@bs.send] external write : (t, ~key: keyOption=?, unit) => unit = "";
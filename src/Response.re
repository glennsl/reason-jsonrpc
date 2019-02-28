type t = result(Yojson.Safe.json, string);

let is = (msg: Yojson.Safe.json) =>
  !Utility.hasMethod(msg) && Utility.hasId(msg);

let parse = (msg: Yojson.Safe.json) => {

  let result = switch (Utility.hasResult(msg))  {
  | true => 
        let result = msg |> Yojson.Safe.Util.member("result");
        Ok(result)
  | false => let error = msg |> Yojson.Safe.Util.member("error") |> Yojson.Safe.to_string; 
Log.error(error);
        Error(error);
  }

  result
};
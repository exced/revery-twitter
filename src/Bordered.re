open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let container =
    Style.[
      backgroundColor(Colors.black),
      border(~color=Colors.black, ~width=1),
      borderRadius(5.0),
      overflow(`Hidden),
    ];

  let subContainer =
    Style.[
      backgroundColor(Colors.white),
      border(~color=Colors.white, ~width=1),
      borderRadius(5.0),
      overflow(`Hidden),
    ];
};

let component = React.component("Bordered");

let make = (~children, ()) =>
  component(hooks =>
    (
      hooks,
      <View style=Styles.container>
        <View style=Styles.subContainer> ...children </View>
      </View>,
    )
  );

let createElement = (~children, ()) => make(children, ());
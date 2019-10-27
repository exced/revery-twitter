open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let text =
    Style.[
      color(Color.hex("#00ffff")),
      fontFamily("Roboto-Regular.ttf"),
      fontSize(24),
    ];
};

let component = React.component("Home");

let make = () =>
  component(hooks =>
    (
      hooks,
      <View>
        <Text style=Styles.text text="Home TEST" />
        <Tweet id="1" />
        <Tweet id="2" />
        <Tweet id="3" />
        <Tweet id="4" />
        <Tweet id="5" />
      </View>,
    )
  );

let createElement = (~children as _, ()) => make();
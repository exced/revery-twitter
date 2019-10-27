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

let component = React.component("Profile");

let make = () =>
  component(hooks => (hooks, <Text style=Styles.text text="Profile" />));

let createElement = (~children as _, ()) => make();
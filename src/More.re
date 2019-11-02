open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let text =
    Style.[
      color(Theme.Colors.black),
      fontFamily("Roboto-Regular.ttf"),
      fontSize(15),
    ];
};

let component = React.component("More");

let make = () =>
  component(hooks => (hooks, <Text style=Styles.text text="More" />));

let createElement = (~children as _, ()) => make();
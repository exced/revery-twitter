open Revery;
open Revery.UI;
open Revery.UI.Components;

module Routes = {
  type t =
    | Home
    | Profile
    | Tweet(string);
};

module Link = {
  module Styles = {
    let text = active =>
      Style.[
        color(active ? Color.hex("#1e88e5") : Colors.black),
        fontFamily("Roboto-Black.ttf"),
        fontSize(24),
      ];
  };

  let component = React.component("Link");

  let make = (~text, ~onClick, ~active, ()) =>
    component(hooks =>
      (
        hooks,
        <Clickable onClick>
          <Text style={Styles.text(active)} text />
        </Clickable>,
      )
    );

  let createElement = (~children as _, ~text, ~onClick, ~active, ()) =>
    make(~text, ~onClick, ~active, ());
};
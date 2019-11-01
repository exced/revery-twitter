open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {};

let component = React.component("Home");

let make = () =>
  component(hooks =>
    (
      hooks,
      <View>
        <Tweet id="1" />
        <Tweet id="2" />
        <Tweet id="3" />
        <Tweet id="4" />
        <Tweet id="5" />
      </View>,
    )
  );

let createElement = (~children as _, ()) => make();
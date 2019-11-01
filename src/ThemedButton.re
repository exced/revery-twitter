open Revery;
open Revery.UI;
open Revery.UI.Components;

module Styles = {
  let viewContainer = (kind, ~hovered, ~centered) => {
    let c =
      switch (kind, hovered) {
      | (Theme.Primary, true) => Theme.Colors.blue
      | (Theme.Primary, false) => Theme.Colors.lightBlue
      | (Theme.Secondary, true) => Theme.Colors.lightGrey
      | (Theme.Secondary, false) => Theme.Colors.white
      };

    let h = 49;

    Style.[
      minHeight(h),
      border(~color=c, ~width=Theme.Spacing.m),
      borderRadius(float_of_int(h) /. 2.0),
      backgroundColor(c),
      justifyContent(centered ? `Center : `FlexStart),
      alignItems(`Center),
      flexDirection(`Row),
    ];
  };

  let text = (kind, ~hovered, ~active) => {
    let textColor =
      switch (kind, hovered, active) {
      | (Theme.Primary, _, _) => Theme.Colors.white
      | (Theme.Secondary, true, _) => Theme.Colors.blue
      | (Theme.Secondary, false, true) => Theme.Colors.blue
      | (Theme.Secondary, false, false) => Theme.Colors.black
      };

    Style.[fontFamily("Roboto-Black.ttf"), fontSize(15), color(textColor)];
  };
};

type state = {
  disabled: bool,
  hovered: bool,
};

type action =
  | SetDisabled(bool)
  | SetHovered(bool);

let reducer = (action: action, state) => {
  switch (action) {
  | SetDisabled(disabled) => {...state, disabled}
  | SetHovered(hovered) => {...state, hovered}
  };
};

let component = React.component("ThemedButton");

let initialState = {disabled: false, hovered: false};

let make = (~kind, ~text, ~onClick, ~centered, ~active, ()) =>
  component(hooks => {
    let (state, dispatch, hooks) =
      Hooks.reducer(~initialState, reducer, hooks);

    (
      hooks,
      <Clickable onClick>
        <View
          onMouseOver={_ => dispatch(SetHovered(true))}
          onMouseOut={_ => dispatch(SetHovered(false))}
          style={Styles.viewContainer(
            kind,
            ~hovered=state.hovered,
            ~centered,
          )}>
          <Text
            style={Styles.text(kind, ~hovered=state.hovered, ~active)}
            text
          />
        </View>
      </Clickable>,
    );
  });

let createElement =
    (
      ~children as _,
      ~kind,
      ~text,
      ~onClick,
      ~centered=true,
      ~active=false,
      (),
    ) =>
  make(~kind, ~text, ~onClick, ~centered, ~active, ());
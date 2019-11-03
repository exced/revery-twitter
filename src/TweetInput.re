open Revery;
open Revery.UI;
open Revery.UI.Components;

type size = {
  height: int,
  width: int,
};

let boxSize = {height: 200, width: 400};

module CloseButton = {
  module Styles = {
    let container = hovered => {
      let containerColor =
        hovered ? Theme.Colors.lightGrey : Theme.Colors.white;

      Style.[
        margin(Theme.Spacing.m),
        width(Theme.Spacing.xxl),
        height(Theme.Spacing.xxl),
        border(~color=containerColor, ~width=Theme.Spacing.m),
        borderRadius(float_of_int(Theme.Spacing.xxl) /. 2.0),
        backgroundColor(containerColor),
        justifyContent(`FlexStart),
        alignItems(`Center),
        flexDirection(`Row),
      ];
    };

    let text =
      Style.[
        marginLeft(Theme.Spacing.s),
        marginTop(Theme.Spacing.s),
        fontFamily("Roboto-Black.ttf"),
        fontSize(15),
        color(Theme.Colors.blue),
      ];
  };

  type state = {hovered: bool};

  type action =
    | SetHovered(bool);

  let reducer = (action: action, state) => {
    switch (action) {
    | SetHovered(hovered) => {...state, hovered}
    };
  };

  let component = React.component("ThemedButton");

  let initialState = {hovered: false};

  let make = (~onClick, ()) =>
    component(hooks => {
      let (state, dispatch, hooks) =
        Hooks.reducer(~initialState, reducer, hooks);

      (
        hooks,
        <Clickable onClick>
          <View
            onMouseOver={_ => dispatch(SetHovered(true))}
            onMouseOut={_ => dispatch(SetHovered(false))}
            style={Styles.container(state.hovered)}>
            <Text style=Styles.text text="X" />
          </View>
        </Clickable>,
      );
    });

  let createElement = (~children as _, ~onClick, ()) => make(~onClick, ());
};

module TweetButton = {
  module Styles = {
    let container =
      Style.[
        justifyContent(`FlexEnd),
        alignItems(`Center),
        flexDirection(`Row),
      ];

    let textContainer = hovered => {
      let containerColor =
        hovered ? Theme.Colors.lightGrey : Theme.Colors.white;

      Style.[
        width(70),
        margin(Theme.Spacing.m),
        border(~color=containerColor, ~width=Theme.Spacing.m),
        borderRadius(float_of_int(Theme.Spacing.xxl) /. 2.0),
        backgroundColor(containerColor),
      ];
    };

    let text =
      Style.[
        marginLeft(Theme.Spacing.s),
        marginTop(Theme.Spacing.s),
        fontFamily("Roboto-Black.ttf"),
        fontSize(15),
        color(Theme.Colors.blue),
      ];
  };

  type state = {hovered: bool};

  type action =
    | SetHovered(bool);

  let reducer = (action: action, state) => {
    switch (action) {
    | SetHovered(hovered) => {...state, hovered}
    };
  };

  let component = React.component("ThemedButton");

  let initialState = {hovered: false};

  let make = (~onClick, ()) =>
    component(hooks => {
      let (state, dispatch, hooks) =
        Hooks.reducer(~initialState, reducer, hooks);

      (
        hooks,
        <Clickable onClick>
          <View style=Styles.container>
            <View
              onMouseOver={_ => dispatch(SetHovered(true))}
              onMouseOut={_ => dispatch(SetHovered(false))}
              style={Styles.textContainer(state.hovered)}>
              <Text style=Styles.text text="Tweet" />
            </View>
          </View>
        </Clickable>,
      );
    });

  let createElement = (~children as _, ~onClick, ()) => make(~onClick, ());
};

module Styles = {
  let container =
    Style.[
      backgroundColor(Theme.Colors.white),
      width(boxSize.width),
      height(boxSize.height),
    ];

  let header =
    Style.[
      width(boxSize.width),
      borderBottom(~color=Theme.Colors.black, ~width=1),
    ];

  let input =
    Style.[
      fontSize(15),
      border(~width=0, ~color=Colors.transparentWhite),
      height(boxSize.height - 2 * Theme.Spacing.xl),
      width(boxSize.width),
      borderBottom(~color=Theme.Colors.black, ~width=1),
    ];
};

type state = {value: string};

type action =
  | SetValue(string);

let reducer = (action: action, state) => {
  switch (action) {
  | SetValue(value) => {...state, value}
  };
};

let component = React.component(__MODULE__);

let initialState = {value: ""};

let make = (~width, ~visible, ~toggleTweetInput, ~addTweet, ()) =>
  component(hooks => {
    let (state, dispatch, hooks) =
      Hooks.reducer(~initialState, reducer, hooks);

    let mid = (width - boxSize.width) / 2;

    let tweet = () => {
      addTweet(state.value);
      dispatch(SetValue(""));
      toggleTweetInput();
    };

    let view =
      <Positioned top=50 left=mid>
        <Bordered>
          <View style=Styles.container>
            <View style=Styles.header>
              <CloseButton onClick=toggleTweetInput />
            </View>
            <Input
              style=Styles.input
              placeholder="What's happening ?"
              value={state.value}
              onChange={({value, _}) => dispatch(SetValue(value))}
            />
          </View>
          <View style=Styles.header> <TweetButton onClick=tweet /> </View>
        </Bordered>
      </Positioned>;

    (hooks, visible ? view : <View />);
  });

let createElement =
    (~children as _, ~width, ~visible, ~toggleTweetInput, ~addTweet, ()) =>
  make(~width, ~visible, ~toggleTweetInput, ~addTweet, ());
open Revery;
open Revery.UI;
open Revery.UI.Components;

module Main = {
  open Router;

  module Styles = {
    let container =
      Style.[
        flexGrow(1),
        justifyContent(`Center),
        flexDirection(`Row),
        backgroundColor(Colors.white),
      ];
    let mainContainer =
      Style.[
        backgroundColor(Theme.Colors.white),
        borderLeft(~color=Theme.Colors.grey, ~width=Theme.Spacing.xxs),
        borderRight(~color=Theme.Colors.grey, ~width=Theme.Spacing.xxs),
      ];
  };

  type action =
    | ChangeRoute(Routes.t);

  let component = React.component("Root");

  let make = () =>
    component(hooks => {
      let (route, dispatch, hooks) =
        Hooks.reducer(
          ~initialState=Routes.Home,
          (action, _state) =>
            switch (action) {
            | ChangeRoute(newRoute) => newRoute
            },
          hooks,
        );

      let setRoute = route => dispatch(ChangeRoute(route));

      let mainPanel =
        switch (route) {
        | Home => <Home />
        | Profile => <Profile />
        | Tweet(id) => <Tweet id />
        };

      (
        hooks,
        <View style=Styles.container>
          <Sidebar setRoute currentRoute=route />
          <View style=Styles.mainContainer> mainPanel </View>
        </View>,
      );
    });

  let createElement = (~children as _, ()) => make();
};

let init = app => {
  let _ = Log.listen((_, msg) => print_endline(msg));

  let win =
    App.createWindow(
      ~createOptions=WindowCreateOptions.create(~width=1216, ~height=864, ()),
      app,
      "ReveryTwitter",
    );

  let _ = UI.start(win, <Main />);
  ();
};

App.start(init);
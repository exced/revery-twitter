open Revery;
open Revery.UI;
open Revery.UI.Components;

module Main = {
  open Router;

  module Styles = {
    let sidebarContainer =
      Style.[
        position(`Absolute),
        bottom(0),
        top(0),
        left(0),
        right(0),
        flexDirection(`Row),
        backgroundColor(Color.hex("#e3f2fd")),
      ];
    let mainContainer =
      Style.[
        position(`Absolute),
        top(0),
        left(175),
        right(0),
        bottom(0),
        backgroundColor(Colors.white),
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
        <View onMouseWheel={_ => ()} style=Styles.sidebarContainer>
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
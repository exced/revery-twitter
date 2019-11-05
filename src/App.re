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
        minWidth(500),
        backgroundColor(Theme.Colors.white),
        borderLeft(~color=Theme.Colors.grey, ~width=Theme.Spacing.xxs),
        borderRight(~color=Theme.Colors.grey, ~width=Theme.Spacing.xxs),
      ];
  };

  type state = {
    tweets: list(Data.tweet),
    tweetInputVisible: bool,
    activeRoute: Routes.t,
  };

  type action =
    | AddTweet(Data.tweet)
    | SetTweetInputVisible(bool)
    | ToggleTweetInput
    | SetActiveRoute(Routes.t);

  let reducer = (action: action, state) => {
    switch (action) {
    | AddTweet(tweet) => {...state, tweets: [tweet, ...state.tweets]}
    | SetTweetInputVisible(tweetInputVisible) => {
        ...state,
        tweetInputVisible,
      }
    | ToggleTweetInput => {
        ...state,
        tweetInputVisible: !state.tweetInputVisible,
      }
    | SetActiveRoute(activeRoute) => {...state, activeRoute}
    };
  };

  let component = React.component("Root");

  let initialState = {
    tweets: Data.tweets,
    tweetInputVisible: false,
    activeRoute: Routes.Home,
  };

  let make = (~width, ~height, ()) =>
    component(hooks => {
      let (state, dispatch, hooks) =
        Hooks.reducer(~initialState, reducer, hooks);

      let setRoute = route => dispatch(SetActiveRoute(route));

      let toggleTweetInput = () => dispatch(ToggleTweetInput);

      let addTweet = text => {
        Data.next_tweet_id := Data.next_tweet_id^ + 1;

        let tweet: Data.tweet = {
          tweet_id: string_of_int(Data.next_tweet_id^),
          ref: None,
          text,
          img: None,
          author: Data.user1,
        };
        dispatch(AddTweet(tweet));
      };

      let mainPanel =
        switch (state.activeRoute) {
        | Home => <Home tweets={state.tweets} />
        | Explore => <Explore />
        | Notifications => <Notifications />
        | Messages => <Messages />
        | Bookmarks => <Bookmarks />
        | Lists => <Lists />
        | Profile => <Profile />
        | More => <More />
        };

      (
        hooks,
        <View style=Styles.container>
          <Sidebar
            setRoute
            currentRoute={state.activeRoute}
            toggleTweetInput
          />
          <TweetInput
            width
            visible={state.tweetInputVisible}
            toggleTweetInput
            addTweet
          />
          <View style=Styles.mainContainer> mainPanel </View>
        </View>,
      );
    });

  let createElement = (~children as _, ~width, ~height, ()) =>
    make(~width, ~height, ());
};

let init = app => {
  let _ = Log.listen((_, msg) => print_endline(msg));

  let width = 1216;
  let height = 864;

  let win =
    App.createWindow(
      ~createOptions=WindowCreateOptions.create(~width, ~height, ()),
      app,
      "ReveryTwitter",
    );

  let _ = UI.start(win, <Main width height />);
  ();
};

App.start(init);
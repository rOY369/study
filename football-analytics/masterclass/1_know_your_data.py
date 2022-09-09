import numpy as np
import pandas as pd
import json

# analysis league - la liga
# season - 2019/2020


pd.set_option("display.max_rows", 150)
pd.set_option("display.max_columns", 50)


events_df = pd.read_csv("./data/matchwise_events_data.csv")
meta_df = pd.read_csv("./data/season_matchwise_data.csv")

# pandas basics

events_df.info()

events_df.columns.values

events_df.shape

events_df.dtypes


# events data description
# period = 1 indicates first half, 2 is second half
# type = starting lineup, tactics.lineup is all players


# getting all event types ids and names

events_df[["type.id", "type.name"]].drop_duplicates()

passes_df = events_df[events_df["type.id"] == 30]

# merging events and meta data

columns_to_merge = [
    "match_id",
    "match_date",
    "kick_off",
    "home_score",
    "away_score",
    "home_team.home_team_id",
    "home_team.home_team_name",
    "away_team.away_team_id",
    "away_team.away_team_name",
]

events_df = pd.merge(
    events_df, meta_df[columns_to_merge], how="left", on=["match_id"]
)
events_df.columns.values

# adding started column in events

all_lineups = pd.DataFrame()
for match_id in events_df.match_id.unique():
    started_lineups_df = events_df[
        (events_df["type.id"] == 35) & (events_df["match_id"] == match_id)
    ]["tactics.lineup"]

    lineups_1 = pd.json_normalize(
        json.loads(started_lineups_df.iloc[0].replace("'", '"'))
    )
    lineups_2 = pd.json_normalize(
        json.loads(started_lineups_df.iloc[1].replace("'", '"'))
    )

    lineups = pd.concat([lineups_1, lineups_2])

    # for adding match id as first column
    lineups.insert(0, "match_id", match_id)
    lineups["started"] = 1

    all_lineups = pd.concat([all_lineups, lineups])

print(all_lineups.columns.values)
events_df = pd.merge(
    events_df, all_lineups, how="left", on=["match_id", "player.id"]
)


# calculating minutes played column
# where replacement.id is not null
substitution_df = events_df[
    ["match_id", "substitution.replacement.id", "minute"]
].dropna(subset=["substitution.replacement.id"])

substitution_df.rename(
    {
        "minute": "minimumMinute",
        "substitution.replacement.id": "substituted_player_id",
    }
)

events_df = pd.merge(
    events_df,
    substitution_df,
    how="left",
    left_on=["match_id", "player.id"],
    right=["match_id", "substituted_player_id"],
)

events_df["minimumMinute"] = np.where(
    events_df["started"] == 1, 0, events_df["minimumMinute"]
)

mins_played_df = (
    events_df.groupby(["match_id", "player.id"])
    .agg(
        {
            "player.name": "first",
            "team.name": "first",
            "minimumMinute": "first",
            "minute": "max",
        }
    )
    .reset_index()
)

mins_played_df["mins_played"] = mins_played_df["minute"].subtract(
    mins_played_df["minimumMinute"]
)

events_df = pd.merge(
    events_df,
    mins_played_df[["match_id", "player.id", "mins_played"]],
    how="left",
    on=["match_id", "player.id"],
)

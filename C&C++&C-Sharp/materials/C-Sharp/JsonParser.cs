using System;
using System.Collections.Generic;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using Wolf_Island.Core.Entities.Service;

namespace Wolf_Island.Core.DataLoader
{
    internal class Loader
    {

        public static Dictionary<string, IConfig> GetFullRegistry(string AnimalJsonFileName, string FoodJsonFileName)
        {
            var animalRegistry = GetRegistryFromFile<AnimalsList, AnimalData>(AnimalJsonFileName, root => root.Animals);
            var foodRegistry = GetRegistryFromFile<FoodList, FoodData>(FoodJsonFileName, root => root.Food);
            var fullRegistry = new Dictionary<string, IConfig>(animalRegistry, StringComparer.OrdinalIgnoreCase);

            foreach (var item in foodRegistry)
                fullRegistry[item.Key] = item.Value;

            return fullRegistry;
        }
        public static Dictionary<string, IConfig> GetRegistryFromFile<TList, TItem>(string jsonFileName, Func<TList, List<TItem>?> listSelector)
            where TItem : class, IConfig
        {
            var list = LoadListFromFile<TList, TItem>(jsonFileName, listSelector);
            return ToRegistry(list);
        }

        public static Dictionary<string, IConfig> GetRegistryFromJsonText<TList, TItem>(string jsonText, Func<TList, List<TItem>?> listSelector)
            where TItem : class, IConfig
        {
            var list = LoadListFromJsonText<TList, TItem>(jsonText, listSelector);
            return ToRegistry(list);
        }

        public static List<TItem> LoadListFromFile<TList, TItem>(string jsonFileName, Func<TList, List<TItem>?> listSelector)
            where TItem : class, IConfig
        {
            ArgumentNullException.ThrowIfNull(jsonFileName);

            if (!File.Exists(jsonFileName))
                throw new FileNotFoundException($"File not found: {jsonFileName}");

            string json = File.ReadAllText(jsonFileName);
            return LoadListFromJsonText<TList, TItem>(json, listSelector);
        }

        public static List<TItem> LoadListFromJsonText<TList, TItem>(string jsonText,Func<TList, List<TItem>?> listSelector)
            where TItem : class, IConfig
        {
            ArgumentNullException.ThrowIfNull(jsonText);

            if (string.IsNullOrWhiteSpace(jsonText))  throw new InvalidDataException("JSON text is empty");

            var options = new JsonSerializerOptions
            {
                PropertyNameCaseInsensitive = true,
                Converters = { new JsonStringEnumConverter(allowIntegerValues: true) }
            };

            var data = JsonSerializer.Deserialize<TList>(jsonText, options)
                       ?? throw new InvalidDataException("Failed to deserialize config");

            var list = listSelector(data);

            if (list is null || list.Count == 0)
                throw new InvalidDataException("Config list is empty");

            return list;
        }

        private static Dictionary<string, IConfig> ToRegistry<TItem>(List<TItem> items)
            where TItem : class, IConfig
        {
            var registry = new Dictionary<string, IConfig>(StringComparer.OrdinalIgnoreCase);

            foreach (var item in items)
            {
                if (string.IsNullOrWhiteSpace(item.Id))
                    throw new InvalidDataException($"{typeof(TItem).Name} has empty Id");

                registry[item.Id] = item;
            }

            return registry;
        }
    }
}
